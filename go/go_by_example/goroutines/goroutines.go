package main

import (
    "fmt"
    "time"
)

// a goroutine is a lightweight thread of execution

func f(from string) {
    for i := 0; i < 33; i++ {
        fmt.Println(from, ":", i)
    }
}

func main() {
    // suppose we have a function call f(s). Here's how we'd call that in the usual way,
    // running it synchronously.
    f("direct")

    // to invoke this function in a goroutine, use go f(s). This new goroutine
    // will execute concurrently with the calling one.
    go f("goroutine")
    go f("clown")

    // you can also strart a goroutine for an anonymous function call
    go func(msg string) {
        fmt.Println(msg)
    }("going")

    // our two function calls are running asynchronously in separate goroutines now.
    // Wait for them to finish (for a more robust approach, use a WaitGroup).
    time.Sleep(time.Second)
    fmt.Println("done")
}
