package main

import (
    "bufio"
    "fmt"
    "os"
)

// main function that runs when the program gets executed
func main() {
    // declare a variable counts, it's a result of making 
    // a map where strings are keys and ints are values
    counts := make(map[string]int)

    // declare a var named input that is a new scanner
    // that can get info from stdin, line by line
    input := bufio.NewScanner(os.Stdin)
    // for item in call to input.scan
    // it seems like it returns a iterator of sorts
    // apply ++ to the entry 
    for input.Scan() {
        counts[input.Text()]++
    }
    // NOTE: ignoring potential errors from input.Err()
    // for every line in the map (keys of it)
    // print out the number of times it repeats, and the line itself
    for line, n := range counts {
      if n > 1{
        fmt.Printf("%d\t%s\n", n, line)
      }
    }
}

