package main

import (
    "fmt"
)

func main() {
    // an array of 5 ints. populated by the zero value for the type
    // for ints, it's a straight '0'
    var a [5]int
    fmt.Println("empty: ", a)

    // you can use the array[index] notation to get or set values
    a[4] = 3
    fmt.Println("set:   ", a)
    fmt.Println("get: ", a[4])

    // the builtin len returns the length of the array
    fmt.Println("length: ", len(a))

    // declare and init an array on one line:
    b := [5]int{1, 2, 3, 4, 5}
    fmt.Println("dcl: ", b)

    // arrays are one-dimensional but you can compose types to 
    // build multi-dimensional data structures
    var twoD [2][3]int
    for i := 0; i < 2; i++ {
        for j := 0; j < 3; j++ {
            twoD[i][j] = i + j
        }
    }
    fmt.Println("2d: ", twoD)

    // you'll see slices more often than arrays in typical go
}
