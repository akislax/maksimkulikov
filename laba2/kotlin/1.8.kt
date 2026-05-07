fun main() {
    println("Введите строку S: ")
    var s = readln()
    println("Введите строку T: ")
    var t = readln()
    for (i in 0 until s.lenght()){
        for( j in 0 until t.lenght()){
            var part = s.substring(i, i + j)
            var part_1 = part
            var ch = 0
            for (k in 0 intil t.lenght()){
                var count_t = 0
                var count_part = 0
                for (m in 0 until t.lenght()){
                    if (t[m] == part[k]){
                        count_t++
                    }
                    if (part[m] == part[k]){
                        count_part++
                    }
                }
                if (count_part > count_t){
                    ch++
                }
            }
        }
    }
    if (result == ""){
        println("Не найдено")
    } else {
        println("Результат: $result")
    }
}