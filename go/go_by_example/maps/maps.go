package main

import "fmt"

func main() {
    // map[key-type]val-type
    m := make(map[string]int)
    
    m["k1"] = 7
    m["k2"] = 13

    fmt.Println("map:", m)

    v1 := m["k1"]
    fmt.Println("v1:", v1)
    fmt.Println("len:", len(m))

    delete(m, "k2")

    fmt.Println("mad:", m)
    fmt.Println("len:", len(m))

    // the optional second argument returned from getting a value from a map
    // indicates whether the key was present in the map. This can be used
    // to disambiguate between missing keys and keys with zero values
    // like 0 or "". Here we didn't need the value itself, so we ignored it 
    // with a blank identifier _

    _, presence := m["k2"]
    fmt.Println("presence:", presence)

    // as with other data structures, you can declare and init on one line:
    n := map[string]int{"foo": 1, "bar": 2}
    fmt.Println("map:", n)
}

