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
	var comicId int = 2503
	f, err := os.Create("./xkcd.json")
	check(err)
	w := bufio.NewWriter(f)
	w.WriteString("{\"comics\": [\n")

	var count int = 0

	for {
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

		fmt.Printf("Wrote %d bytes\n", n)

		w.Flush()
		comicId += 1
	}

	w.WriteString("]}\n")
	w.Flush()
}

// TODO
// - [x] generate valid URLs for all comics
// - [ ] ping each of them and write the JSON results to a file.
