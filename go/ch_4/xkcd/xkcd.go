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

func main() {
	fmt.Println("Hello XKCD")

	var comicId int = 1

	for comicId < 100 {
		fmt.Println(getURL(comicId))

		resp, err := http.Get(getURL(comicId))
		if err != nil {
			log.Fatalln(err)
		}

		body, err := ioutil.ReadAll(resp.Body)
		if err != nil {
			log.Fatalln(err)
		}

		stringifiedBody := string(body)
		log.Printf(stringifiedBody)

		comicId += 1
	}

}

// TODO
// - [x] generate valid URLs for all comics
// - [ ] ping each of them and write the JSON results to a file.
