package main

import (
	"fmt"
    "encoding/csv"
    //"net"
    "io/ioutil"
    //"net/url"
	"io"
	"net/http"
	"os"
	"time"
)

func check(err error) {
	if err != nil {
		panic(err)
	}
}

func main() {
	start := time.Now()
    // make makes a channel for strings
    // a channel is a communication mechanism that allows one goroutine
    // to pass values of a specified type to another goroutine
    // the function main runs in a goroutine and the go statement creates
    // additional goroutines.
	ch := make(chan string)
    fmt.Printf("before creating channels\n")

    // get all csv 

    type website struct {
        i string
        url string
    }

    csvFile, err := os.Open("top-1m.csv")
    if err != nil {
        fmt.Println(err)
    }
    fmt.Println("Successfully opened the csv file.")
    defer csvFile.Close()

    csvLines, err := csv.NewReader(csvFile).ReadAll()

    for _, line := range csvLines {
        site := website {
            i: line[0],
            url: line[1],
        }
        fmt.Println("fetching " + site.url)
        go fetch("https://" + site.url, ch) // start a goroutine
	}

	for range csvLines {
		fmt.Println(<-ch) // receive from channel ch
	}

	fmt.Printf("%.2fs elapsed\n", time.Since(start).Seconds())
}

func fetch(src_url string, ch chan<- string) {
	start := time.Now()
	resp, err := http.Get(src_url)
	if err != nil {
		ch <- fmt.Sprint(err) // send to channel ch
		return
	}

    //u, err := url.Parse(src_url)

    // w, err := os.Create(u.Host + ".out.html")
    // if err != nil {
    //     panic(err)
    // }
    // defer defers the execution of the function
    // until the surrounding function returns
    //defer w.Close()

	nbytes, err := io.Copy(ioutil.Discard, resp.Body)
	resp.Body.Close() // don't leak resources
	if err != nil {
		ch <- fmt.Sprintf("while reading %s: %v", src_url, err)
		return
	}
	secs := time.Since(start).Seconds()
	ch <- fmt.Sprintf("%.2fs %7d %s", secs, nbytes, src_url)
}
