package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
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

func loadJSON() {
	// read the json file into memory
	jsonFile, err := os.Open("xkcd.json")
	check(err)
	fmt.Println("successfully opened xkcd.json")
	defer jsonFile.Close()

	byteValue, _ := ioutil.ReadAll(jsonFile)
	var comics Comics

	// parse in as an array of Comic structs
	json.Unmarshal(byteValue, &comics)

	for _, comic := range comics.Comics {
        fmt.Println("printing comic")
		printComic(comic)
	}

	// declare a global var with the necessary size

}

func getURL(comicId int) (url string) {
	return "https://xkcd.com/" + fmt.Sprint(comicId) + "/info.0.json"
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
		resp, err := http.Get(getURL(comicId))

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

func main() {
	loadJSON()
}

// TODO
// - [x] generate valid URLs for all comics
// - [x] ping each of them and write the JSON results to a file.
// - [x] write a fn that loads the json into memory using structs
// - [ ] write a search function
// - [ ] enable querying
