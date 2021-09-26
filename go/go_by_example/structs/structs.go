package main

import "fmt"

type person struct {
	name string
	age  int
}

func newPerson(name string) *person {
	p := person{name: name}
	p.age = 42
    // you can safely return the pointer to a local variable as the local 
    // variable will survive the scope of the function
	return &p
}

func main() {

    // this syntax creates a new struct
	fmt.Println(person{"Bob", 20})
    // you can name the fields when initializing the struct
	fmt.Println(person{name: "Alice", age: 30})
    // omitted fields will be zero-valued
	fmt.Println(person{name: "Fred"})
    // an & prefix yields a pointer to the struct
	fmt.Println(&person{name: "Ann", age: 40})
    // it's idiomatic to encapsulate new struct creation in constructor functions
    fmt.Println(newPerson("Jon"))

    // access struct fields with a dot
    s := person{name: "Sean", age: 50}
    fmt.Println(s.name)

    // you can also use dots with struct pointers, the pointers are automatically
    // dereferenced
    sp := &s 
    fmt.Println(sp.age)

    // structs are mutable
    sp.age = 51
    fmt.Println(sp.age)
}
