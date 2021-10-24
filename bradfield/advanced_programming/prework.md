**Prerequisites.** Make sure you're comfortable with the following concepts from _The Go Programming Language_:

- [x] * Variables and pointers (2.3)
- [x] * Composite types (4.1 - 4.4)

**Readings.** Begin by reading the following:

- [x] * [Go Data Structures](https://research.swtch.com/godata)
- [x] * [A comprehensive analysis of Golang's map design](https://www.fatalerrors.org/a/a-comprehensive-analysis-of-golang-s-map-design.html)

- [x] You might also find [Inside the Map Implementation](https://www.youtube.com/watch?v=Tl7mi9QmLns) helpful if you prefer video, but this is optional.

**Implementation.** Next, implement the following functions:[^go]

- [ ] * Given a `string`, return its length (number of bytes) without using `len`.
- [ ] * Given a `type Point struct { x int, y int }`, return its `y` coordinate without using `p.y`.
- [ ] * Given an `[]int`, return the sum of values without using `range` or `[]`.
- [ ] * Given a `map[int]int`, return the max value, again without using `range` or `[]`.

The goal of this implementation exercise is for you to gain familiarity with the underlying representations of these basic types (hence the strange constraints).

You will find it helpful to use `uintptr` and `unsafe.Pointer` (see 13.1 - 13.2 of _The Go Programming Language_). You will likely also want to consult the Go source code, especially `runtime/map.go`, which you can find at `/usr/local/go/src` or on [Github](https://github.com/golang/go).
