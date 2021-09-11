package main

import (
	"fmt"
	"image"
	"image/color"
	"image/gif"
	"io"
	"log"
	"math"
	"math/rand"
	"net/http"
	"strconv"
	"sync"
)

var mu sync.Mutex
var count int

var palette = []color.Color{color.Black, color.RGBA{0x23, 0xf1, 0xba, 0xff}, color.White}

const (
	whiteIndex = 0 // first color in the palette
	greenIndex = 1 // second color
	blackIndex = 2 // third color in the palette
)

func lissajous(out io.Writer, cycles int) {
	const (
		res     = 0.0001 // angular resolution
		size    = 200    // image canvas covers [-size..+size]
		nframes = 100    // number of animation frames
		delay   = 4      // delay between the frames in 10ms units
	)

	var cycles_float float64
	cycles_float = float64(cycles)
	freq := rand.Float64() * 3.0 // relative frequency of the y oscillator
	anim := gif.GIF{LoopCount: nframes}
	phase := 0.0 // phase difference
	for i := 0; i < nframes; i++ {
		rect := image.Rect(0, 0, 2*size+1, 2*size+1)
		img := image.NewPaletted(rect, palette)
		for t := 0.0; t < cycles_float*2*math.Pi; t += res {
			x := math.Sin(t)
			y := math.Sin(t*freq + phase)
			img.SetColorIndex(size+int(x*size+0.5), size+int(y*size+0.5), blackIndex)
		}
		phase += 0.1
		anim.Delay = append(anim.Delay, delay)
		anim.Image = append(anim.Image, img)

	}
	gif.EncodeAll(out, &anim) // ignoring errors btw
}

func main() {
	handler := func(w http.ResponseWriter, r *http.Request) {
		query := r.URL.Query()
		fmt.Printf("query: %s\n", query)
		var cycles string
		cycles = query.Get("cycles")
		fmt.Printf("value of cycles: %s", cycles)
		var cycles_int int
		cycles_int, _ = strconv.Atoi(cycles)
        if cycles_int < 1 {
            cycles_int = 1
        }
		lissajous(w, cycles_int)
	}
	http.HandleFunc("/", handler)
	http.HandleFunc("/count", counter)
	log.Fatal(http.ListenAndServe("localhost:8000", nil))
}

// handler echoes the Path component of the requested URL.
func handler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "%s %s %s\n", r.Method, r.URL, r.Proto)
	for k, v := range r.Header {
		fmt.Fprintf(w, "Header[%q] = %q\n", k, v)
	}
	fmt.Fprintf(w, "Host = %q\n", r.Host)
	fmt.Fprintf(w, "RemoteAddr = %q\n", r.RemoteAddr)
	if err := r.ParseForm(); err != nil {
		log.Print(err)
	}
	for k, v := range r.Form {
		fmt.Fprintf(w, "Form[%q] = %q\n", k, v)
	}
}

// counter echoes the number of calls so far.
func counter(w http.ResponseWriter, r *http.Request) {
	mu.Lock()
	fmt.Fprintf(w, "Count %d\n", count)
	mu.Unlock()
}
