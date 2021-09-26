package main

import (
	"fmt"
	"time"
)

func main() {

    // let's look at basic rate limiting. Suppose we want to limit our handling
    // of incoming requests. We'll server these requests off a channel of the same name.
	requests := make(chan int, 5)
	for i := 1; i <= 5; i++ {
		requests <- i
	}
	close(requests)

    // this limiter channel will receive a value every 200 milliseconds. tihs is the regulator
    // in our rate limiting scheme
	limiter := time.Tick(200 * time.Millisecond)

    // by blocking on a receive from the limiter chanel before serving each
    // request, we limit ourselves to 1 request every 200 milliseconds
	for req := range requests {
		<-limiter
		fmt.Println("request", req, time.Now())
	}

    // we may want to allow short bursts of requests in our rae limiting scheme
    // while preserving the overall rate limit. We can accomplish this by buffering
    // our limiter channel. This burtyLimiter channel will allow bursts of up to 3 events.
	burstyLimiter := make(chan time.Time, 3)

    // fill up the channel to represent allowed bursting.
	for i := 0; i < 3; i++ {
		burstyLimiter <- time.Now()
	}

    // every 200 milliseconds we'll try to add a new value to burstyLimiter
    // up to the limit of 3.
	go func() {
		for t := range time.Tick(200 * time.Millisecond) {
			burstyLimiter <- t
		}
	}()

    // now, simulate 5 more incoming requests. The first 3 of these will benefit
    // from the burst capability of burtyLimiter
	burstyRequests := make(chan int, 5)
	for i := 1; i <= 5; i++ {
		burstyRequests <- i
	}
	close(burstyRequests)
	for req := range burstyRequests {
		<-burstyLimiter
		fmt.Println("request", req, time.Now())
	}
}
