package main

import (
	"example.com/user/hello/morestrings"
	"fmt"
    "github.com/google/go-cmp/cmp"
)

func main() {
	fmt.Println("Hello world")
	fmt.Println(morestrings.ReverseRunes("!oG ,olleH"))
	fmt.Println(cmp.Diff("Hello world!", "Hello Go"))
}
