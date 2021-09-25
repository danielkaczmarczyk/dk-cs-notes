package main

import  (
    "fmt"
)

func main() {
    // slices are a key data type in go, giving a more powerful interface
    // to sequences than arrays
    // unlike arrays, slices are typed just by the elements they contain,
    // not their number. To create an empty slice with a non-zero length
    // use the builtin `make`. Here we make a slice of strings of length 3, 
    // initially zero-valued
    s := make([]string, 3)
    fmt.Println("emp:", s)
    fmt.Println("len:", len(s))

    // set and get just like arrays
    s[0] = "a"
    s[1] = "b"
    s[2] = "c"
    fmt.Println("set:", s)
    fmt.Println("get:", s[2])

    // builtin append returns a slice containing one or more 
    // new values. Note to accept a return value.

    s = append(s, "d")
    s = append(s, "e", "f")
    fmt.Println("apd:", s)

    // slices can also be copied.
    c := make([]string, len(s))
    copy(c, s)
    fmt.Println("cpy:", c)

    // slices support a "slice" operator with syntax slice[low:high].
    // below gets elements 2,3, and 4.
    l := s[2:5]
    fmt.Println("sl1:", l)

    // this slices up to (excluding) 5
    l = s[:5]
    fmt.Println("sl2:", l)

    // up from and including 2
    l = s[2:]
    fmt.Println("sl3:", l)

    // we can declare and init on a single line as well
    t := []string{"g", "h", "i"}
    fmt.Println("dcl:", t)

    // slices can be composed into multi-dimensional data structures.
    // the lenght of the inner slices can vary, unlike with multi-dimensional arrays
    twoD := make([][]int, 3)
    for i := 0; i < 3; i++ {
        innerLen := i + 1
        twoD[i] = make([]int, innerLen)
        for j := 0; j < innerLen; j++ {
            twoD[i][j] = i + j
        }
    }
    fmt.Println("twd:", twoD)
}
