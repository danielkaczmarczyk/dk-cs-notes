package main

import (
    "fmt"
    "time"
)

// we often want to execute go code at some point in the future, or repeatedly
// at some interval. Go's built-in timer and ticker features make both tasks easy.
// we'll look first at the timers and then at tickers.

func main() {

    // timers represent a single event in the future. you tell the timer how long
    // you want to wait, and it provides a channel that will be notified at
    // that time. This timer will wait 2 seconds.
    timer1 := time.NewTimer(2 * time.Second)

    // the <-timer.C blocks on the timer's channel C until it sends a 
    // value indicating that the timer fired.
    <-timer1.C
    fmt.Println("Timer 1 fired")

    // if you just want to wait, you can just use time.Sleep. One reason
    // a timer can be more useful is that you can cancel it before it fires.
    timer2 := time.NewTimer(time.Second)
    go func() {
        <-timer2.C
        fmt.Println("Timer 2 fired")
    }()
    stop2 := timer2.Stop()
    if stop2 {
        fmt.Println("Timer 2 stopped")
    }

    // give the timer2 enough time to fire, if it ever was going to, to show
    // it is in fact stopped
    time.Sleep(2 * time.Second)
}
