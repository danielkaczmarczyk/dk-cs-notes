package main

import (
	"fmt"
	"io"
	"net/http"
	"os"
)

func main() {
	for _, url := range os.Args[1:] {
		resp, err := http.Get(url)
		if err != nil {
			fmt.Fprintf(os.Stderr, "fetch: %v\n", err)
			os.Exit(1)
		}
		bytes, err := io.Copy(os.Stdout, resp.Body)
		if err != nil {
			panic(err)
		}

		fmt.Printf("The number of bytes are: %d\n", bytes)
	}
}
