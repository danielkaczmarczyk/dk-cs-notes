// Clock1 is a TCP server that periodically writes the time.
package main

import (
	"io"
	"log"
	"net"
	"time"
)

func main() {
	// Listen announces on the local network address
	// in our case, it's localhost:8000
	listener, err := net.Listen("tcp", "localhost:8000")
	if err != nil {
		log.Fatal(err)
	}

	// loop forever, and listen
	for {
		// Accept is blocking and will wait for the connection
		conn, err := listener.Accept()
		if err != nil {
			log.Print(err) // e.g, connection aborted
			continue
		}
		// pass the connection object to the handler
		handleConn(conn) // handle one connection at a time
	}
}

func handleConn(c net.Conn) {
  // defer closing the connection until the end of the fn
	defer c.Close()
	for {
		_, err := io.WriteString(c, time.Now().Format("15:04:05\n"))
		if err != nil {
			return // e.g., client disconnected
		}
		time.Sleep(1 * time.Second)
	}
}
