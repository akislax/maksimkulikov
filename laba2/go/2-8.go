package main

import (
	"fmt"
	"sort"
)

func main1() {
	var n int
	fmt.Println("Введите количество встреч:")
	fmt.Scan(&n)

	type Meeting struct {
		ID    int
		Start int
		End   int
	}
	var meetings []Meeting
	fmt.Println("Введите время начала и окончания каждой встречи (формат: start end): ")
	for i := 0; i < n; i++ {
		var start, end int
		fmt.Scan(&start, &end)
		meetings = append(meetings, Meeting{ID: i + 1, Start: start, End: end})
	}
	sort.Slice(meetings, func(i, j int) bool {
		return meetings[i].End < meetings[j].End
	})

	var result []int
	var count = 0
	var last_end = -1

	for i := 0; i < n; i++ {
		if meetings[i].Start >= last_end {
			result = append(result, meetings[i].ID)
			last_end = meetings[i].End
			count++
		}
	}
	fmt.Println("Количество выбранных встреч: ", count)
	fmt.Println("Номера встреч: ")
	for i := 0; i < len(result); i++ {
		fmt.Print(result[i]+1, " ")
	}

}
