package main

import (
	"fmt"
	"sync"
	"time"
)

// this is the function we will run in every goroutine.
func worker(id int) {
	fmt.Printf("Worker %d starting\n", id)

	time.Sleep(time.Second)
	fmt.Printf("Worker %d done\n", id)
}

func main() {

	// this waitgroup is used to wait for all the goroutines launched here to finish.
    // note if a waitgroup is explicitly passed int ofunctions, it should be done by pointer.
    // this would be important if, for example, our worker had to launch additional goroutines.
	var wg sync.WaitGroup

    // launch several goroutines and increment the waitgroup counter for each
	for i := 1; i <= 5; i++ {
		wg.Add(1)

        // avoid reuse of the same i value in each goroutine closure.
		i := i

        // wrap the worker call in a closure that makes sure to tell the waitgroup
        // that this worker is done. this way the worker itself doesn not have to be
        // aware of the concurrency primitives involved in its execution.
		go func() {
			defer wg.Done()
			worker(i)
		}()
	}

    // block until the waitgroup counter goes back to 0; all the workers notified they're done.
	wg.Wait()

    // note this approach has no straightforward way to propagate errors from workers.
    // for more advanced use cases, consider using the errgroup package.
}
