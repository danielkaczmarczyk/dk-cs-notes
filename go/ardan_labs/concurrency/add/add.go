package main

import (
	"fmt"
	"math/rand"
	"runtime"
	"sync"
	"sync/atomic"
	"time"
)

func init() {
	rand.Seed(time.Now().UnixNano())
}

func main() {
	numbers := generateList(1e7)

	fmt.Println(add(numbers))
	fmt.Println(addConcurrent(runtime.NumCPU(), numbers))
}

func generateList(totalNumbers int) []int {
	numbers := make([]int, totalNumbers)
	for i := 0; i < totalNumbers; i++ {
		numbers[i] = rand.Intn(totalNumbers)
	}
	return numbers
}

// add function is a workload that is suitable for out of order execution
// the collection of integers could be broken up into smaller lists
// and those lists could be processed concurrently. Once all the smaller
// lists are summed, the set of sums could be added together to produce the same
// answer as the sequential version
// since the function is perfoming a cpu bound worklad and nothing it does could
// cause the goroutine go into a waiting state. this means using one goroutine per
// os/hardware thread is all that is needed for good throughput.
func add(numbers []int) int {
	var v int
	for _, n := range numbers {
		v += n
	}
	return v
}

func addConcurrent(goroutines int, numbers []int) int {
  var v int64
  totalNumbers := len(numbers)
  lastGoroutine := goroutines - 1
  stride := totalNumbers / goroutines

  var wg sync.WaitGroup
  wg.Add(goroutines)

  for g := 0; g < goroutines; g++ {
    go func(g int) {
      start := g * stride
      end := start + stride
      if g == lastGoroutine {
        end = totalNumbers
      }

      var lv int
      for _, n := range numbers[start:end] {
        lv += n
      }

      atomic.AddInt64(&v, int64(lv))
      wg.Done()
    }(g)
  }

  wg.Wait()

  return int(v)
}
