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
	at := 0
	size := 0
	var value string

	fmt.Printf("Welcome. This is linked list example written in Go. \n\n")

	for order != -1 {
		print(head)
		managePointer(head, tail)
		fmt.Println("size : " + strconv.Itoa(size))
		fmt.Println("1) Add at first")
		fmt.Println("2) Add at last")
		fmt.Println("3) Add after index at...")
		fmt.Println("4) Remove by index")
		fmt.Println("5) Remove by value at all")
		fmt.Println("6) Remove by value at first")
		fmt.Println("7) Remove by value at last")

		fmt.Scanln(&order)

		switch order {
		case 1:
			fmt.Printf("string value : ")
			fmt.Scanln(&value)
			addAtFirst(&head, &tail, value, &size)
			break
		case 2:
			fmt.Printf("string value : ")
			fmt.Scanln(&value)
			addAtLast(&head, &tail, value, &size)
			break
		case 3:
			fmt.Printf("string value : ")
			fmt.Scanln(&value)
			fmt.Printf("position : ")
			fmt.Scanln(&at)
			addAfterIndexAt(&head, &tail, value, at, &size)
			break
		case 4:
			fmt.Printf("position : ")
			fmt.Scanln(&at)
			removeByIndexAt(&head, &tail, at, &size)
			break
		case 5:
			fmt.Printf("string value : ")
			fmt.Scanln(&value)
			removeByValueAtAll(&head, &tail, value, &size)
			break
		case 6:
			fmt.Printf("string value : ")
			fmt.Scanln(&value)
			removeByValueAtFirst(&head, &tail, value, &size)
			break
		case 7:
			fmt.Printf("string value : ")
			fmt.Scanln(&value)
			removeByValueAtLast(&head, &tail, value, &size)
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

func addAtFirst(head **Node, tail **Node, value string, size *int) {
	temp := createNewNode(value)

	if *size != 0 {
		(**head).last = temp
		(*temp).next = (*head)
	} else {
		(*tail) = temp
	}

	(*head) = temp

	(*size)++
}

func addAtLast(head **Node, tail **Node, value string, size *int) {
	newHead := *head
	temp := createNewNode(value)

	if *size == 0 {
		(*head) = temp
		(*tail) = temp
	} else {
		for (*newHead).next != nil {
			newHead = (*newHead).next
		}

		(*temp).last = newHead
		(*newHead).next = temp
		(*tail) = temp
	}
	(*size)++
}

func addAfterIndexAt(head **Node, tail **Node, value string, at int, size *int) {
	if *size <= at || at < 0 {
		fmt.Printf("\n[Error] Invalid Index")
		return
	}

	newHead := (*head)
	temp := createNewNode(value)

	if at == *size-1 {
		if at == 0 {
			*head = temp
		} else {
			for (*newHead).next != nil {
				newHead = (*newHead).next
			}
			(*temp).last = newHead
			(*newHead).next = temp
		}
		(*tail) = temp
	} else {
		for i := 0; i < at; i++ {
			newHead = (*newHead).next
		}

		temp2 := (*newHead).next
		(*newHead).next = temp
		(*temp).last = newHead

		(*temp).next = temp2
		(*temp2).last = temp2
	}

	(*size)++
}

func removeByIndexAt(head **Node, tail **Node, at int, size *int) {
	if *size <= at || at < 0 {
		fmt.Printf("\n[Error] Invalid Index.")
		return
	}

	newHead := *head
	var temp *Node = nil

	if at == 0 {
		(*head) = (**head).next
		if (*head) != nil {
			(**head).last = nil
		} else {
			(*tail) = nil
		}
	} else {
		if at == *size-1 {
			newHead = (*tail)

			(*(**tail).last).next = nil
			(*tail) = (**tail).last
		} else {
			for i := 0; i < at; i++ {
				temp = newHead
				newHead = (*newHead).next
			}

			(*temp).next = (*newHead).next
			(*(*newHead).next).last = temp
		}
	}

	// Go language has Garbage Collector.
	newHead = nil

	(*size)--
}

func removeByValueAtAll(head **Node, tail **Node, value string, size *int) {
	if *size == 0 {
		fmt.Printf("\n[Error] The size is 0.")
		return
	}

	newHead := *head
	index := 0
	count := 0

	for newHead != nil {
		data := (*newHead).data
		newHead = (*newHead).next

		if data == value {
			count++
			removeByIndexAt(head, tail, index, size)
			index--
		}
		index++
	}

	if count == 0 {
		fmt.Println("There is no value named '" + value + "'.")
	} else if count == 1 {
		fmt.Println("1 item is removed.")
	} else {
		fmt.Println(strconv.Itoa(count) + " items are removed.")
	}
}

func removeByValueAtFirst(head **Node, tail **Node, value string, size *int) {
	if *size == 0 {
		fmt.Printf("\n[Error] The size is 0.")
		return
	}

	newHead := *head
	index := 0
	isExist := false

	for newHead != nil {
		data := (*newHead).data
		newHead = (*newHead).next

		if data == value {
			isExist = true
			removeByIndexAt(head, tail, index, size)
			break
		}
		index++
	}

	if !isExist {
		fmt.Println("There is no value named '" + value + "'.")
	} else {
		fmt.Println("The first item is removed.")
	}
}

func removeByValueAtLast(head **Node, tail **Node, value string, size *int) {
	if *size == 0 {
		fmt.Printf("\n[Error] The size is 0.")
		return
	}

	newTail := *tail
	index := (*size) - 1
	isExist := false

	for newTail != nil {
		data := (*newTail).data
		newTail = (*newTail).last

		if data == value {
			isExist = true
			removeByIndexAt(head, tail, index, size)
			break
		}
		index--
	}

	if !isExist {
		fmt.Println("There is no value named '" + value + "'.")
	} else {
		fmt.Println("The first item is removed.")
	}
}
