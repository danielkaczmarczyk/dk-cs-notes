package main

import (
    "fmt"
)

func main() {
    i := 1

    // the most basic type
    for i <= 3 {
        fmt.Println(i)
        i = i + 1
    }

    // classic initial/condition/after for loop
    for j := 7; j <= 9; j++ {
        fmt.Println(j)
    }

    // for without a condition will loop repeatedly until you 
    // break out of the loop or return from the enclosing function.
    for {
        fmt.Println("loop")
        break
    }

    // you can also continue, as expected
    for n := 0; n <= 5; n++ {
        if n % 2 == 0 {
            continue
        }
        fmt.Println(n)
    }

    // there are additional for forms, we will look at them later
}
