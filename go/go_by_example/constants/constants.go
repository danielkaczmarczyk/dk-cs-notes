package main

import (
	"fmt"
	"math"
)

// const declares a constant value
const s string = "constant"

func main() {
    fmt.Println(s)

    // const can appear anywhere var can
    const n = 5000000

    // constant expressions perform arithmetic with arbitrary precision
    const d = 3e20 / n
    fmt.Println(d)

    // a numeric constant has no type until it's given one, such as by
    // explicit conversion
    fmt.Println(int64(d))

    // a number can be given a type by using it in a context that
    // requires one, such as variable assignment or a function call.
    // for example here, math.Sin expects a float64
    fmt.Println(math.cin(n))
    
}
