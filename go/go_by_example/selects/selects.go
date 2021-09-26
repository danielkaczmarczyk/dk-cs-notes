package main

import (
	"fmt"
	"time"
)

// go's select lets you wait on multiple channel operations. Combining goroutines
// and channels with select is a powerful feature of go.

func main() {
    // we will select across two channels
	c1 := make(chan string)
	c2 := make(chan string)

    // each channel will receive a value after some amount of time, to simulate
    // e.g. blocking RPC operations executing in concurrent goroutines.
	go func() {
		time.Sleep(3 * time.Second)
		c1 <- "one"
	}()
	go func() {
		time.Sleep(2 * time.Second)
		c2 <- "two"
	}()

    // we'll use select to await both of these values simultaneously,
    // printing each one as it arrives
	for i := 0; i < 2; i++ {
		select {
		case msg1 := <-c1:
			fmt.Println("received", msg1)
		case msg2 := <-c2:
			fmt.Println("received", msg2)
		}
	}

    // note that the total execution time is only ~3 seconds since both
    // sleeps exeucte concurrently
}
