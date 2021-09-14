package main

import (
    "fmt"
	"io/ioutil"
	"log"
)

// TODO time it
// TODO make it run concurrently on different parts of the slice

func main() {
	_, err := ioutil.ReadFile("2_input.txt")
	if err != nil {
		log.Fatal(err)
	}

    myArray := [...]int{1, 2}

    fmt.Printf("%d\n", len(myArray))
	fmt.Printf("%v\n", myArray)
}
