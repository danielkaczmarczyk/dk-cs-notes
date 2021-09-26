package main

import ( 
    "fmt"
    "time"
)

// here's the worker, of which we'll run several concurrent instances.
// these workers will receive work on the jobs channel and send the corresponding
// results on results.
// we'll sleep a second per job to simulate an expensive task.
func worker(id int, jobs <-chan int, results chan<- int) {
    for j := range jobs {
        fmt.Println("worker", id, "started job", j)
        time.Sleep(time.Second)
        fmt.Println("worker", id, "finished job", j)
        results <- j * 2
    }
}

func main() {

    // in order to use our pool of workers, we need to send them work and 
    // collect their results. We make 2 channels for this.
    const numJobs = 5
    jobs := make(chan int, numJobs)
    results := make(chan int, numJobs)

    // this starts up 3 workers, initially blcoked because there are no jobs yet.
    for w := 1; w <= 3; w++ {
        go worker(w, jobs, results)
    }

    // here we send 5 jobs and then close that channel to indicate that's all the work we have.
    for j:= 1; j <= numJobs; j++ {
        jobs <- j
    }
    close(jobs)


    // finally we collect all the results of the work.
    // this also ensures that the worker goroutines have finished. an
    // alternative way to wait for multiple goroutines is to use a waitgroup.
    for a:= 1; a <= numJobs; a++ {
        <-results
    }

    // our running program shows the 5 jobs being executed by various workers.
    // the program only takes about 2 seconds despite doing 5 seconds of total work
    // cuz there are 3 workers operating concurrently.
}
