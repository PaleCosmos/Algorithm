package main

import (
	"fmt"
)

//Exercise
func main() {
	var str string = "My First Go Project.\n"
	number := 10
	number++

	for i := 0; i < number; i++ {

		fmt.Printf(str)
	}
}
