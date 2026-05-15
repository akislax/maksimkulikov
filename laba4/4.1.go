package main

import (
	"fmt"
	"math"
)

type Interval struct {
	a, b float64
}

func f(x float64) float64 {
	return (x * x) - math.Cos(x+0.3)
}

func f1(x float64) float64 {
	return math.Sqrt(math.Cos(x + 0.3))
}

func findIntervals(start, end, step float64) []Interval {
	var found []Interval
	for x := start; x < end; x += step {
		if f(x)*f(x+step) <= 0 {
			found = append(found, Interval{x, x + step})
		}
	}
	return found
}

func proizvod(x float64) float64 {
	h := 1e-7
	return (f(x+h) - f(x)) / h
}

func proizvod2(x float64) float64 {
	h := 1e-7
	return (proizvod(x+h) - proizvod(x)) / h
}

func main() {
	E := 4e-4
	roots := findIntervals(-2.0, 1.4, 0.1)

	for i, root := range roots {
		fmt.Printf("\n--- РЕЗУЛЬТАТЫ ДЛЯ КОРНЯ %d ---\n", i+1)

		fmt.Println("N\ta_n\t\tb_n\t\tb_n - a_n")
		a, b := root.a, root.b
		n := 0
		for math.Abs(b-a) > E {
			fmt.Printf("%d\t%.6f\t%.6f\t%.6f\n", n, a, b, math.Abs(b-a))
			n++
			c := (a + b) / 2
			if f(a)*f(c) < 0 {
				b = c
			} else {
				a = c
			}
		}
		fmt.Printf("По методу половинного деления получаем %d корень = %.6f\n", i+1, (a+b)/2)

		fmt.Println("\nN\tX_n\t\tX_n+1\t\tX_n+1 - X_n")
		x := root.a
		x1 := f1(x)
		n = 0
		for math.Abs(x1-x) > E {
			fmt.Printf("%d\t%.6f\t%.6f\t%.6f\n", n, x, x1, math.Abs(x1-x))
			n++
			x = x1
			x1 = f1(x)
		}
		fmt.Printf("По методу итераций корень %d = %.6f\n", i+1, x1)

		fmt.Println("\nN\tX_n\t\tX_n+1\t\tX_n+1 - X_n")
		x0 := root.a
		if f(x0)*proizvod2(x0) <= 0 {
			x0 = root.b
		}
		x_newton := x0 - (f(x0) / proizvod(x0))
		n = 0
		for math.Abs(x_newton-x0) >= E {
			fmt.Printf("%d\t%.6f\t%.6f\t%.6f\n", n, x0, x_newton, math.Abs(x_newton-x0))
			n++
			x0 = x_newton
			x_newton = x0 - (f(x0) / proizvod(x0))
		}
		fmt.Printf("Корень по Ньютону: %.6f\n", x_newton)
	}
}
