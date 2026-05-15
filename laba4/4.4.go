package main

import (
	"fmt"
)

func main() {
	fmt.Println("Введите количество кандидатов:")
	var n int
	fmt.Scan(&n)

	fmt.Print("Введите количество групп избирателей: ")
	var g int
	fmt.Scan(&g)

	counts := make([]int, g)
	votes := make([][]int, g)
	k := 0

	for i := 0; i < g; i++ {
		fmt.Printf("Группа №%d - количество человек: ", i+1)
		fmt.Scan(&counts[i])
		k += counts[i]

		fmt.Printf("Группа №%d - порядок кандидатов: ", i+1)
		votes[i] = make([]int, n)
		for j := 0; j < n; j++ {
			fmt.Scan(&votes[i][j])
		}
	}

	// Подсчёт очков по Борду
	scores := make(map[int]int)
	for i := 0; i < g; i++ {
		for j := 0; j < n; j++ {
			candidate := votes[i][j]
			points := (n - 1 - j)
			scores[candidate] += points * counts[i]
		}
	}

	winnerBorda := -1
	maxPoints := -1
	for candidate, pts := range scores {
		if pts > maxPoints {
			maxPoints = pts
			winnerBorda = candidate
		}
	}
	fmt.Printf("По Борду: %d\n", winnerBorda)

	// Поиск победителя по Кондорсе
	condorcetWinner := -1
outer:
	for candA := range scores {
		for candB := range scores {
			if candA == candB {
				continue
			}
			winsInPair := 0
			for i := 0; i < g; i++ {
				posA, posB := -1, -1
				for j := 0; j < n; j++ {
					if votes[i][j] == candA {
						posA = j
					}
					if votes[i][j] == candB {
						posB = j
					}
				}
				if posA < posB {
					winsInPair += counts[i]
				}
			}
			if winsInPair <= (k - winsInPair) {
				continue outer
			}
		}
		condorcetWinner = candA
		break
	}

	if condorcetWinner != -1 {
		fmt.Printf("По Кондорсе: %d\n", condorcetWinner)
	} else {
		fmt.Println("По Кондорсе: не определён")
	}
}
