package error

import (
	"fmt"
	"os"
)

func Error(src string) {
	fmt.Printf("cart: error: %s\n", src)
}

func Fatal(src string, args ...int) {
	fmt.Printf("cart: fatal: %s\n", src)
	if len(args) > 0 {
		os.Exit(args[0])
	}
	os.Exit(1)
}

func Warn(src string) {
	fmt.Printf("cart: warning: %s\n", src)
}
