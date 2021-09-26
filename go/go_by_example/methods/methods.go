package main

import "fmt"

// go supports _methods_ defined on struct types
type rect struct {
    width, height int
}

// this method has a _receiver_ type of *rect
func (r *rect) area() int {
    return r.width * r.height
}

// methods can be defined for either pointer or value receiver types
// here's an example of a value receiver
func (r rect) perim() int {
    return 2*r.width + 2*r.height 
}

func main() {
    r := rect{width: 10, height: 5}

    fmt.Println("area:", r.area())
    fmt.Println("perim:", r.perim())

    rp := &r

    fmt.Println("area:", rp.area())
    fmt.Println("perim:", rp.perim())

    // go automatically handles the converion between values and pointeres for
    // method calls. you may want to use a pointer receiver type to avoid copying on
    // method calls 
}
