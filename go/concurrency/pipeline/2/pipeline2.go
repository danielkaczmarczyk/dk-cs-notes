package main

import "fmt"

func main() {
  naturals := make(chan int)
  squares := make(chan int)

  // Ccunter
  go func() {
    for x := 0; x < 10; x++ {
      naturals <- x
    }
    close(naturals)
  }()

  // Squarer
  go func() {
    for x := range naturals {
      squares <- x * x
    }
    close(squares)
  }()

  // Printer(in main goroutine)
  for x := range squares {
    fmt.Println(x)
  }
}
