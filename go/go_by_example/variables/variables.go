package main

import "fmt"

func main() {
    // var declares 1 or more variables
    var a = "initial"
    fmt.Println(a)

    // you can declare multiple variables at once
    var b, c int = 1, 2
    fmt.Println(b, c)

    // go will infer the type for you
    var d = true
    fmt.Println(d)

    // and assign sensible defaults
    var e int
    fmt.Println(e)

    // := is shorthand for delcaration and initialization
    f := "apple"
    fmt.Println(f)
}
