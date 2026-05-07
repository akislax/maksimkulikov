package main

import (
	"fmt"
)

func main() {
	var s, t string
	fmt.Println("Введите строку S:")
	fmt.Scan(&s)
	fmt.Println("Введите строку T:")
	fmt.Scan(&t)

	result := ""

	for i := 0; i < len(s); i++ {
		for j := 1; i+j <= len(s); j++ {
			part := s[i : i+j]
			ch := 0

			for k := 0; k < len(t); k++ {
				countInT := 0
				countInPart := 0

				for m := 0; m < len(t); m++ {
					if t[m] == t[k] {
						countInT++
					}
				}

				for m := 0; m < len(part); m++ {
					if part[m] == t[k] {
						countInPart++
					}
				}

				if countInPart >= countInT {
					ch++
				}
			}

			if ch >= len(t) {
				if result == "" || len(part) < len(result) {
					result = part
				}
			}
		}
	}

	if result == "" {
		fmt.Println("Не найдено")
	} else {
		fmt.Println(result)
	}
}
