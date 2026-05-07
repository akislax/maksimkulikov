package main

import "fmt"

func main() {
	var n int
	fmt.Println("Введите ваше N: ")
	fmt.Scan(&n)

	numbers := []int{}
	fmt.Println("Введите ваши числа: ")
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		numbers = append(numbers, num)
	}
	var count int
	count = 0
	for i := 1; i < len(numbers); i++ {
		if numbers[i] == numbers[i-1] {
			count++
		}
	}
	fmt.Println("Количество чисел, равных предыдущему: ", count)

}
