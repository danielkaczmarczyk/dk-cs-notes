package main

import "fmt"

// intSeq returns another function
// the returned function closes over the value of i to form a closure
func intSeq() func() int {
	i := 0
	return func() int {
		i++
		return i
	}
}

func main() {

    // we call intSeq, assigning the result (a function) to nextInt.
    // this function captures its own value of i
    // which will be updated every time we call nextInt
    nextInt := intSeq()

    fmt.Println(nextInt())
    fmt.Println(nextInt())
    fmt.Println(nextInt())

    // to confirm that it's unique to every closure, let's get a new one.
    newInts := intSeq()
    fmt.Println(newInts())

    fmt.Println(nextInt())
}
