package main

import (
    "fmt"
    "time"
)

// we can use channels to synchronize execution across goroutines. Here's an
// example of using a blocking receive to wait for a goroutine to finish, you may
// prefer to use a WaitGroup


// this is the function we will run in a goroutine. The done channel wil lbe used to
// notify another goroutine that this function's work is done.
func worker(done chan bool) {
    fmt.Print("working.")
    time.Sleep(time.Second / 2)
    fmt.Print(".")
    time.Sleep(time.Second / 2)
    time.Sleep(time.Second / 4)
    fmt.Print(".")
    time.Sleep(time.Second)
    fmt.Println("done")

    // send a value to notify that we're done.
    done <- true
}

func main() {
    
    // start a worker goroutine, giving it the channel to notify on.
    done := make(chan bool, 1)
    go worker(done)

    // block until we receive a notification from the worker on the channel
    <-done
    // removing the above line, the program would exit before the worker even started.
}
