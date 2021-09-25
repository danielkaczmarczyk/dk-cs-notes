package main

import "fmt"

func main() {
    // you can use range to sum things in a slice or array.
    nums := []int{2, 3, 4}
    sum := 0
    for _, num := range nums {
        sum += num
    }
    fmt.Println("sum:", sum)

    for i, num := range nums {
        if num == 3 {
            fmt.Println("3 is at index", i)
        }
    }

    // range on map iterates over key/value pairs
    kvs := map[string]string {"a": "apple", "b": "banana"}
    for k, v := range kvs {
        fmt.Printf("%s -> %s\n", k, v)
    }

    // can do keys only too
    for k := range kvs {
        fmt.Printf("%s\n", k)
    }

    // on strings, it iterates over unicode code points
    for i, c := range "go" {
        fmt.Println(i, c)
    }
}
