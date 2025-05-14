package main

import (
	"cart/pkg/error"
	"cart/internal/write"
	"os"
)

func main() {
	if len(os.Args) < 2 {
		error.Fatal("not enough arguemnts")
	}
	write.Write(os.Args[1])
}
