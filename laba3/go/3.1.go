package main

import (
	"fmt"
	"math"
)

func main() {
	var xS, xE, dx float64 = -5.0, 5.0, 0.5
	var y float64
	var n int

	fmt.Println("1. y = -0.5 * (x + 3)^2 + 2")
	fmt.Println("2. y = -x - 1")
	fmt.Println("3. y = sqrt(1 - (x + 2)^2)")
	fmt.Println("4. y = -0.5 * x - 0.5")
	fmt.Println("5. y = -1 - sqrt(1 - (x - 2)^2)")
	fmt.Println("6. y = -x")
	fmt.Println("7. y = 0.5 * (x - 3)^2 - 3")

	fmt.Println("┌───────┬────────────┬────────────┐")
	fmt.Printf("│%6s │ %10s │ %10s │\n", "N", "X", "Y")
	fmt.Println("├───────┼────────────┼────────────┤")

	for x := xS; x <= xE+dx/2; x += dx {
		if x >= -5 && x < -3 {
			y = -0.5*math.Pow(x+3, 2) + 2
			n = 1
		} else if x >= -3 && x < -2 {
			y = -x - 1
			n = 2
		} else if x >= -2 && x < -1 {
			y = math.Sqrt(1 - math.Pow(x+2, 2))
			n = 3
		} else if x >= -1 && x < 1 {
			y = -0.5*x - 0.5
			n = 4
		} else if x >= 1 && x < 2 {
			y = -1 - math.Sqrt(1-math.Pow(x-2, 2))
			n = 5
		} else if x >= 2 && x < 3 {
			y = -x
			n = 6
		} else {
			y = 0.5*math.Pow(x-3, 2) - 3
			n = 7
		}

		fmt.Printf("│%6d │ %10.2f │ %10.2f │\n", n, x, y)
	}

	fmt.Println("└───────┴────────────┴────────────┘")
}
