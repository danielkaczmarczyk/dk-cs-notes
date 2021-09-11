package main

import (
	"bufio"
	"flag"
	"fmt"
	"image"
	"log"
	"os"
	//"image"
	"image/color"
	"image/gif"
	//"io"
	"io/ioutil"
	//"math"
	//"math/rand"
	//"os"
)

func check_basement(seen_basement *bool, floor int, i int) {
	if !*seen_basement && floor == -1 {
		fmt.Printf("Santa entered the basement at character %d\n", i+1)
		*seen_basement = true
	}
}

func main() {
	fptr := flag.String("fpath", "1_input.txt", "file path")
	flag.Parse()
	fmt.Println("value of fpath is:", *fptr)
	data, err := ioutil.ReadFile(*fptr)
	if err != nil {
		fmt.Println("File reading error", err)
		return
	}
	var palette = []color.Color{color.White, color.Black}

	var nframes int = 0

	for _, char := range string(data) {
		if char == '(' || char == ')' {
			nframes += 1
		}
	}

	fmt.Printf("nframes: %d", nframes)

	const (
		whiteIndex = 0
		blackIndex = 1
		size       = 100
		delay      = 8
	)

	anim := gif.GIF{LoopCount: nframes}

	var floor int = 0
	var seen_basement bool = false

	for i, char := range string(data) {
		rect := image.Rect(0, 0, nframes, nframes)
		img := image.NewPaletted(rect, palette)

		if char == '(' {
			floor += 1
			check_basement(&seen_basement, floor, i)
		} else if char == ')' {
			floor -= 1
			check_basement(&seen_basement, floor, i)
		}

		img.SetColorIndex(i, floor, blackIndex)
		img.SetColorIndex(i+1, floor, blackIndex)
		anim.Delay = append(anim.Delay, delay)
		anim.Image = append(anim.Image, img)
	}
	fmt.Printf("The final floor is: %d\n", floor)
	var gifFileName string = "1_out.gif"
	fmt.Printf("Rendering the gif to %s\n", gifFileName)
	file, err := os.Create("./out.gif")
	if err != nil {
        fmt.Println("error when opening file")
        log.Fatal(err)
	}
	writer := bufio.NewWriter(file)
	err = gif.EncodeAll(writer, &anim)
	if err != nil {
        fmt.Println("error when writing gif")
        log.Fatal(err)
	}
	writer.Flush()
    file.Close()
}
