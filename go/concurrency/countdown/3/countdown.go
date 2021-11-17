package main

import (
	"fmt"
	"os"
	"time"
)

func main() {
	abort := make(chan struct{})
	go func() {
		os.Stdin.Read(make([]byte, 1)) // read a single byte
		abort <- struct{}{}
	}()

	fmt.Println("Commencing countdown, press return to abort")
	tick := time.Tick(1 * time.Second)
	for countdown := 3; countdown > 0; countdown-- {
		fmt.Println(countdown)
		select {
		case <-tick:
			// do nothing
		case <-abort:
			fmt.Println("Launch aborted!")
			return
		}
	}
	launch()
}

func launch() {
	fmt.Println("launched!")
}
