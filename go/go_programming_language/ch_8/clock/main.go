package main

import (
	"fmt"
	"io"
	"log"
	"net"
	"time"
)

func main() {
  fmt.Println("initializing listeners")
	listener, err := net.Listen("tcp", "localhost:8000")
	if err != nil {
		log.Fatal(err)
	}

	for {
		conn, err := listener.Accept()
		if err != nil {
			log.Print(err) // e.g connection aborted
			continue
		}
		go handleConn(conn) // handle the connection in a separate goroutine
	}
}

func handleConn(c net.Conn) {
	fmt.Println("Connection started!")
	defer c.Close()
	for {
		_, err := io.WriteString(c, time.Now().Format("15:04:05.0000\n"))
		if err != nil {
      fmt.Println(err)
      return
		}
		time.Sleep(320 * time.Millisecond)
	}
}

