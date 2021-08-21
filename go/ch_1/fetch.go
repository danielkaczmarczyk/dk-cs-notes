package main

import (
	"fmt"
	"io"
    "io/ioutil"
	"net/http"
	"os"
    "time"
)

func main() {
    start := time.Now()
	for _, url := range os.Args[1:] {
		resp, err := http.Get(url)
		if err != nil {
			fmt.Fprintf(os.Stderr, "fetch: %v\n", err)
			os.Exit(1)
		}
		bytes, err := io.Copy(ioutil.Discard, resp.Body)
		if err != nil {
			panic(err)
		}
        fmt.Printf("status: %s", resp.Status)
		fmt.Printf("The number of bytes are: %d\n", bytes)
	}
    fmt.Printf("%.2fs elapsed\n", time.Since(start).Seconds())
}
