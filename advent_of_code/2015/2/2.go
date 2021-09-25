package main

import (
    "fmt"
	"io/ioutil"
	"log"
    "strings"
)

func main() {
	data, err := ioutil.ReadFile("2_input.txt")
	if err != nil {
		log.Fatal(err)
	}

    presents := strings.Split(string(data), "\n")
    demo_presents := presents[:5]

    fmt.Print("Hello World!\n")
    fmt.Printf("amount of presents: %d\n", len(demo_presents))
    fmt.Printf("%s", strings.Split(presents[0], "x"))
}
