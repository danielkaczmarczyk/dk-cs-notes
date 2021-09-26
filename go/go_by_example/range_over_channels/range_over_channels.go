package main

import "fmt"

func main() {

    queue := make(chan string, 3)
    queue <- "one"
    queue <- "two"
    queue <- "three"
    close(queue)

    // the range iterates over each element as it's received from queue.
    // cuz we closed the channel above, the iteration terminates after receiving
    // the 2 elements.
    for elem := range queue {
        fmt.Println(elem)
    }

    // this example also showed that it's possible to close a non-empty channel
    // but still have the remaining values be received
}
