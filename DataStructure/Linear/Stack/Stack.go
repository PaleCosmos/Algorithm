/*
   Copyright 2019 PaleCosmos

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

package main

import (
	"fmt"
	"strconv"
)

type Node struct {
	data string
	next *Node
	last *Node
}

func main() {
	var head *Node = nil
	var tail *Node = nil

	order := 0
	size := 0
	var value string

	fmt.Printf("Welcome. This is stack example written in Go. \n\n")

	for order != -1 {
		print(head)
		managePointer(head, tail)
		fmt.Println("size : " + strconv.Itoa(size))
		fmt.Println("1) Push")
		fmt.Println("2) Pop")

		fmt.Scanln(&order)

		switch order {
		case 1:
			fmt.Printf("string value : ")
			fmt.Scanln(&value)
			push(&head, &tail, value, &size)
			break
		case 2:
			pop(&head, &tail, &size)
			break

		default:
			order = -1
			break
		}

		fmt.Printf("\n\n")
	}

	fmt.Println("Process Exit")
}
func createNewNode(value string) *Node {
	temp := &Node{value, nil, nil}
	return temp
}

func print(head *Node) {
	if head == nil {
		fmt.Println("nil")
		return
	}

	temp := head

	fmt.Print("nil <-> ")

	for temp != nil {
		fmt.Print((*temp).data + " <-> ")
		temp = (*temp).next
	}
	fmt.Println("nil")

}

func managePointer(head *Node, tail *Node) {
	var headStr, tailStr string

	if head == nil {
		headStr = "nil"
	} else {
		headStr = (*head).data
	}

	if tail == nil {
		tailStr = "nil"
	} else {
		tailStr = (*tail).data
	}

	fmt.Println("Head : " + headStr)
	fmt.Println("Tail : " + tailStr)
}

func push(head **Node, tail **Node, value string, size *int) {
	temp := createNewNode(value)

	if *size == 0 {
		(*head) = temp
		(*tail) = temp
	} else {
		(**tail).next = temp
		(*temp).last = (*tail)
		(*tail) = temp
	}

	(*size)++
}

func pop(head **Node, tail **Node, size *int) {

	if *size == 0 {
		fmt.Println("The size is 0.")
		return
	} else if *size == 1 {
		(*tail) = nil
		(*head) = nil
	} else {
		(*tail) = (**tail).last
		(**tail).next = nil
	}

	// Go language has Garbage Collector.
	// temp = nil

	(*size)--
}
