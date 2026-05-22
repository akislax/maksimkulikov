package main

import (
	"fmt"
)

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func main() {
	var a, b int
	fmt.Println("Введите a и b: ")
	fmt.Scan(&a, &b)

	if b == 1 {
		fmt.Print("infinity")
		return
	}

	S := make([][]int, a+1)
	for i := range S {
		S[i] = make([]int, a+1)
	}
	S[0][0] = 1

	for n := 1; n <= a; n++ {
		for k := 1; k <= n; k++ {
			S[n][k] = S[n-1][k-1] + k*S[n-1][k]
		}
	}

	fact := make([]int, a+1)
	for i := range fact {
		fact[i] = 1
	}

	for i := 1; i <= a; i++ {
		fact[i] = fact[i-1] * i
	}

	num := 0

	for k := 1; k <= a; k++ {
		term := S[a][k] * fact[k] * b

		pw := 1
		for i := 0; i < a-k; i++ {
			pw *= (b - 1)
		}

		term *= pw
		num += term
	}

	den := 1
	for i := 0; i < a+1; i++ {
		den *= (b - 1)
	}

	g := gcd(num, den)

	fmt.Printf("%d/%d", num/g, den/g)
}
