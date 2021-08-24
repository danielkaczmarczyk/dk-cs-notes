package main

import (
	"bufio"
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
)

func getURL(comicId int) (url string) {
	return "https://xkcd.com/" + fmt.Sprint(comicId) + "/info.0.json"
}

func check(err error) {
	if err != nil {
		panic(err)
	}
}

func main() {
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

// TODO
// - [x] generate valid URLs for all comics
// - [x] ping each of them and write the JSON results to a file.
