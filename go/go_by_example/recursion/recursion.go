package main

import "fmt"

func fact(n int) int {
    if n == 0 {
        return 1
    }
    return n * fact(n - 1)
}

func main() {
    fmt.Println(fact(7))

    // closures can also be recursive but it requires the closure to be 
    // declared with a typed var explicitly before it's defined.
    var fib func(n int) int
    
    fib = func(n int) int {
        if n < 2 {
            return n
        }
        // since fib was previously declared in main, go knows which function
        // to cal with fib here.
        return fib(n - 1) + fib(n - 2)
    }

    fmt.Println(fib(7))

