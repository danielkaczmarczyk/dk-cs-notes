package main

import (
	"errors"
	"fmt"
)

// in go it's idiomatic to communicate errors via an explicit, separate return
// value. this contrasrts with the exceptions used in languages like java and ruby
// and the overloaded single result / error value sometimes used in c.
// go's apporach makes it easy to see which functions return erros and to handle them using
// the same language constructs employed for any other, non-error tasks.

// by convention, erros are the last return value and have type error, a built-in interface
func f1(arg int) (int, error) {
	if arg == 42 {
		// errors.New constructs a basic error value with the given error message.
		return -1, errors.New("can't work with 42")
	}

	// a nil value in the error position indicates that there was no error.
	return arg + 3, nil
}

// it's possible to use custom types as errors by implementing the Error()
// method on them. Here's a variant on the example above that uses a custom type
// to explicitly represent an argument error.
type argError struct {
	arg  int
	prob string
}

func (e *argError) Error() string {
	return fmt.Sprintf("%d - %s", e.arg, e.prob)
}

func f2(arg int) (int, error) {
	if arg == 42 {

        // in this case we user &argError syntax to build a new struct,
        // supplying values for the two fields arg and prob
		return -1, &argError{arg, "can't worc with it"}
	}
	return arg + 3, nil
}

func main() {
    // the two loops below test out each of our error-returning functions.
    // note that the use of an inline error check on the if line is a common
    // idiom in go code.
	for _, i := range []int{7, 42} {
		if r, e := f1(i); e != nil {
			fmt.Println("f1 failed:", e)
		} else {
			fmt.Println("f1 worked:", r)
		}

	}

	for _, i := range []int{7, 42} {
		if r, e := f2(i); e != nil {
			fmt.Println("f2 failed:", e)
		} else {
			fmt.Println("f2 worked:", r)
		}
	}

    // if you want to programmatically use the data in a custom error, you'll need
    // to get the error as an instance of the custom error type via type assertion
	_, e := f2(42)
	if ae, ok := e.(*argError); ok {
		fmt.Println(ae.arg)
		fmt.Println(ae.prob)
	}
}
