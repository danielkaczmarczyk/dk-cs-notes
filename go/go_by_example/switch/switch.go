package main

import (
    "fmt"
    "time"
)

func main() {
    i := 2
    fmt.Print("write ", i, " as ")
    // here's a basic switch

    switch i {
    case 1:
        fmt.Println("one")
    case 2:
        fmt.Println("two")
    case 3:
        fmt.Println("three")
    }

    switch time.Now().Weekday() {
    // multiple expressions are possible 
    case time.Saturday, time.Sunday:
        fmt.Println("It's the weekend!")
    default:
        fmt.Println("It's a weekday!")
    }

    // switch without an expression is an alt way to 
    // do if else logic. case expressions can also be non-constants
    
    t := time.Now()
    switch {
    case t.Hour() < 12:
        fmt.Println("It's before noon!")
    default:
        fmt.Println("It's after noon!")
    }

    // a type switch compares types instead of values
    // you can use this to discover the type of an interface value
    whatAmI := func(i interface{}) {
        switch t := i.(type) {
        case bool:
            fmt.Println("I'm a bool")
        case int:
            fmt.Println("I'm an int")
        default: 
        fmt.Printf("I don't know the type %T\n", t)
        }
    }
    whatAmI(true)
    whatAmI(1)
    whatAmI("hey")
}
