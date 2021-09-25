package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"os"
	"strings"
	"time"
)

type Comics struct {
	Comics []Comic `json:"comics"`
}

type Comic struct {
	Day        string
	Month      string
	Num        int
	Year       string
	News       string
	Title      string
	SafeTitle  string
	Transcript string
	Img        string
	Alt        string
}

var comics Comics

func printComic(comic Comic) {
	fmt.Println("num: ", comic.Num)
	fmt.Println("day: ", comic.Day)
	fmt.Println("month: ", comic.Month)
	fmt.Println("year: ", comic.Year)
	fmt.Println("news: ", comic.News)
	fmt.Println("title: ", comic.Title)
	fmt.Println("safeTitle: ", comic.SafeTitle)
	fmt.Println("transcript: ", comic.Transcript)
	fmt.Println("img: ", comic.Img)
	fmt.Println("alt: ", comic.Alt)
	fmt.Println("-----------------------")
}

func track(msg string) (string, time.Time) {
	return msg, time.Now()
}

func duration(msg string, start time.Time) {
	log.Printf("%v: %v\n", msg, time.Since(start))
}

func loadJSON() {
	defer duration(track("loading json"))
	// read the json file into memory
	jsonFile, err := os.Open("xkcd.json")
	check(err)
	fmt.Println("successfully opened xkcd.json")
	defer jsonFile.Close()

	byteValue, _ := ioutil.ReadAll(jsonFile)

	// parse in as an array of Comic structs
	json.Unmarshal(byteValue, &comics)

	count := len(comics.Comics)
	fmt.Printf("%d comics loaded into memory\n", count)
}

func getURL(comicId int, json bool) string {
    url := "https://xkcd.com/" + fmt.Sprint(comicId)

	if json {
		url += "/info.0.json"
	}

	return url
}

func check(err error) {
	if err != nil {
		panic(err)
	}
}

func downloadAll() {

	var comicId int = 1
	f, err := os.Create("./xkcd.json")
	check(err)
	w := bufio.NewWriter(f)
	w.WriteString("{\"comics\": [\n")

	var count int = 0

	for {
		if comicId == 404 {
			comicId += 1
			continue
		}

		count++
		resp, err := http.Get(getURL(comicId, true))

		if resp.StatusCode != 200 {
			break
		}

		body, err := ioutil.ReadAll(resp.Body)
		check(err)

		stringifiedBody := string(body)

		if count != 1 {
			w.WriteString(",")
		}
		n, err := w.WriteString(stringifiedBody + "\n")
		check(err)

		fmt.Printf("%d: Wrote %d bytes\n", count, n)

		w.Flush()
		comicId += 1
	}

	w.WriteString("]}\n")
	w.Flush()
}

func checkText(query string, comic Comic) bool {
	var inTitle bool = strings.Contains(comic.Title, query)
	var inAlt bool = strings.Contains(comic.Alt, query)
	var inTranscript bool = strings.Contains(comic.Transcript, query)

	return inTitle || inAlt || inTranscript
}

func search(query string) {
	for _, comic := range comics.Comics {
		if checkText(query, comic) {
			fmt.Printf("Found your comic at: %s\n", getURL(comic.Num, false))
		}
	}
}

func main() {
	loadJSON()

	if len(os.Args[1:]) < 1 {
		fmt.Println("Cannot perform search. Please add queries")
        os.Exit(1)
	}

	for _, arg := range os.Args[1:] {
        search(arg)
	}

}
