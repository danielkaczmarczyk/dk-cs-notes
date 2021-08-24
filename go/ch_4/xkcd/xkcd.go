// download each URL once, and build an offline index.
package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
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

		log.Printf(stringifiedBody)

		comicId += 1
	}

}

// TODO
// - [x] generate valid URLs for all comics
// - [ ] ping each of them and write the JSON results to a file.
