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
	for {
		resp, err := http.Get(getURL(comicId))

		if resp.StatusCode != 200 {
			break
		}

		check(err)

		body, err := ioutil.ReadAll(resp.Body)

		check(err)

		stringifiedBody := string(body)

		f, err := os.Create("./xkcd.json")
		w := bufio.NewWriter(f)

        n, err := w.WriteString(stringifiedBody)
        check(err)
        fmt.Printf("Wrote %d bytes\n", n)

        w.Flush()
		comicId += 1
	}

}

// TODO
// - [x] generate valid URLs for all comics
// - [ ] ping each of them and write the JSON results to a file.
