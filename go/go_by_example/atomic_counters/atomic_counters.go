package main

import (
    "fmt"
    "sync"
    "sync/atomic"
)

func main() {

    // we'll use an unsigned integer to represent our counter
    var ops uint64
    // a waitgroup will help us wait for all goroutines to finish their work
    var wg sync.WaitGroup

    // we'll start 50 goroutines that each increment the counter exactly 1000 times.
    for i := 0; i < 50; i++ {
        wg.Add(1)

        // to atomically increment the counter we use AddUint64, giving it
        // the memory address of our ops counter with the & syntax
        go func() {
            for c := 0; c < 1000; c++ {
                atomic.AddUint64(&ops, 1)
            }
            wg.Done()
        }()
    }

    wg.Wait()

    // it's safe to access ops now cause we know no other goroutie is writing to it.
    // reading atomics safely while they are being update is also bossible,
    // using funcs like atomic.LoadUint64.
    fmt.Println("ops:", ops)

    // we expect exactly 50,000 operations. Had we used the non-atomic ops++ to increment
    // the counter, we'd likely get a different number, changing between runs, because
    // the goroutines would interfere with each other. moreover, we'd get data race failuers
    // when running with the -race flag.

}
