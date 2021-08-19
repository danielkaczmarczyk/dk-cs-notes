package main

import (
	"image"
	"image/color"
	"image/gif"
	"io"
	"math"
	"math/rand"
	"os"
)

var palette = []color.Color{color.Black, color.RGBA{0x23, 0xf1, 0xba, 0xff}, color.White}

const (
	whiteIndex = 0 // first color in the palette
    greenIndex = 1 // second color
	blackIndex = 2 // third color in the palette
)

func main() {
	lissajous(os.Stdout)
}

func lissajous(out io.Writer) {
	const (
		cycles  = 5      // nubmer of complete oscillations
		res     = 0.0001 // angular resolution
		size    = 200    // image canvas covers [-size..+size]
		nframes = 100    // number of animation frames
		delay   = 4      // delay between the frames in 10ms units
	)

	freq := rand.Float64() * 3.0 // relative frequency of the y oscillator
	anim := gif.GIF{LoopCount: nframes}
	phase := 0.0 // phase difference
	for i := 0; i < nframes; i++ {
		rect := image.Rect(0, 0, 2*size+1, 2*size+1)
		img := image.NewPaletted(rect, palette)
		for t := 0.0; t < cycles*2*math.Pi; t += res {
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
