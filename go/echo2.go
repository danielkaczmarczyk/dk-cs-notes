// echo 2 prints its cl args
package main

import (
    "fmt"
    "os"
    "strconv"
    "time"
)

func main() {
    start := time.Now()

    fmt.Println(os.Args[0])
    s := ""
    for i, arg := range os.Args[1:] {
        s = strconv.Itoa(i) + ": " +  arg
        fmt.Println(s)
    }

    fmt.Printf(":%.2fs elapsed\n", time.Since(start).Seconds())
}
