package main

import (
	"fmt"
	"unsafe"
)

/*
- [ ] * Given a `map[int]int`, return the max value, again without using `range` or `[]`.
*/

// new() returns a pointer to type
var POINTER_SIZE = unsafe.Sizeof(new(int))

func main() {
	msg := "hello!"
	fmt.Println(_len(msg))
	point := Point{1, 123}
	fmt.Println(_getY(point))
	nums := []int{3, 3, 5}
	fmt.Println(_sum(nums))
}

func _len(s string) int {
	beginning := unsafe.Pointer(&s)
	return *(*int)(unsafe.Pointer(uintptr(beginning) + POINTER_SIZE))
}

type Point struct {
	x int
	y int
}

func _getY(point Point) int {
	beginning := unsafe.Pointer(&point)
	return *(*int)(unsafe.Pointer(uintptr(beginning) + unsafe.Sizeof(point.x)))
}

func _sum(nums []int) int {
  var sum int
	// get pointer to the first element
	beginning := unsafe.Pointer(&nums)
	// access length to know the loop boundary
	length := *(*int)(unsafe.Pointer(uintptr(beginning) + POINTER_SIZE))
  n := *(**int)(unsafe.Pointer(uintptr(beginning)))

  pointerToN := unsafe.Pointer(n)
  fmt.Println(uintptr(pointerToN))
  fmt.Println(uintptr(pointerToN) + 1)
  for i := 0; i < length; i++ {
    sum += *(*int)(pointerToN)
    pointerToN = unsafe.Pointer(uintptr(pointerToN) + POINTER_SIZE)
  }
	return sum 
}

func _max_map() int {
  //
  return 0
}
