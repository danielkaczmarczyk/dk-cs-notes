// this is where usually you describe what the package is supposed to be
// a couple sentences here will do
package main

import (
	"fmt"
	"os"
)

func main() {
	var way = "one_at_a_time"
    way = "oops"
	// `s` and `sep` are variables of type string.
	// they are declared but not initialized, so they get assigned a zero for
	// its type, effectively, a "" for string type.
	var s, sep string

	if way == "one_at_a_time" {
		for i := 1; i < len(os.Args); i++ {
			s += sep + os.Args[i]
			sep = "__%__"
		}
		fmt.Println(s)
	} else {
		for i := 1; i < len(os.Args); i++ {
			fmt.Println(os.Args[i])
		}
	}
}
