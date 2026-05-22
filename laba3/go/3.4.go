package main

import (
	"fmt"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func bestMove(a []int64, pos int, n int, m int, lastTake int) int {
	limit := min(m, n-pos)

	var bestSum int64 = -1000000000000000000
	bestK := -1
	var curSum int64 = 0

	for k := 1; k <= limit; k++ {
		curSum += a[pos+k-1]

		if k == lastTake {
			continue
		}

		if bestK == -1 || curSum > bestSum || (curSum == bestSum && k < bestK) {
			bestSum = curSum
			bestK = k
		}
	}

	if bestK == -1 {
		bestK = 1
	}

	return bestK
}

func main() {
	var n, m int
	fmt.Println(" Введите n и m: ")
	fmt.Scan(&n, &m)

	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	var pavel, vika int64 = 0, 0
	var lastPavel, lastVika int = 0, 0

	pos := 0
	turn := 0

	for pos < n {
		var take int

		if turn == 0 {
			take = bestMove(a, pos, n, m, lastPavel)
		} else {
			take = bestMove(a, pos, n, m, lastVika)
		}

		var sum int64 = 0
		for i := 0; i < take; i++ {
			sum += a[pos+i]
		}

		if turn == 0 {
			pavel += sum
			lastPavel = take
		} else {
			vika += sum
			lastVika = take
		}

		pos += take
		turn = 1 - turn
	}

	if pavel > vika {
		fmt.Print(1)
	} else {
		fmt.Print(0)
	}
}
