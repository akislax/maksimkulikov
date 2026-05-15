package main

import (
	"fmt"
)

func main() {
	fmt.Println("Введите количество кандидатов: ")
	var n int
	fmt.Scan(&n)

	fmt.Print("Введите количество избирателей: ")
	var k int
	fmt.Scan(&k)

	votes := make([][]int, 0)

	for i := 0; i < k; i++ {
		fmt.Printf("Избиратель №%d: ", i+1)
		single_votes := make([]int, 0)
		for j := 0; j < n; j++ {
			var id int
			fmt.Scan(&id)
			single_votes = append(single_votes, id)
		}
		votes = append(votes, single_votes)
	}

	scores := make(map[int]int)
	for i := 0; i < k; i++ {
		for j := 0; j < n; j++ {
			candidate := votes[i][j]
			points := n - 1 - j
			scores[candidate] += points
		}
	}

	winner_borda := -1
	max_points := -1
	for candidate, points := range scores {
		if points > max_points {
			max_points = points
			winner_borda = candidate
		}
	}
	fmt.Printf("По Борду: %d\n", winner_borda)

	condorcet_winner := -1

	for candA := range scores {
		wins_everyone := true

		for candB := range scores {
			if candA == candB {
				continue
			}

			wins_in_pair := 0
			for i := 0; i < k; i++ {
				posA := -1
				posB := -1
				for j := 0; j < n; j++ {
					if votes[i][j] == candA {
						posA = j
					}
					if votes[i][j] == candB {
						posB = j
					}
				}
				if posA < posB {
					wins_in_pair++
				}
			}

			if wins_in_pair <= (k - wins_in_pair) {
				wins_everyone = false
				break
			}
		}

		if wins_everyone {
			condorcet_winner = candA
			break
		}
	}

	if condorcet_winner != -1 {
		fmt.Printf("По Кондорсе: %d\n", condorcet_winner)
	} else {
		fmt.Println("По Кондорсе: не определён")
	}
}
