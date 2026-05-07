fun main() {
    println("Введите строку S: ")
    var s = readln()
    println("Введите строку T: ")
    var t = readln()
    var result = ""
    for (i in 0 until s.length){
        for( j in 1..s.length - i){
            var part = s.substring(i, i + j)
            var part_1 = part
            var ch = 0
            if (part.length == t.length) {
                for (k in 0 until t.length){
                    var count_t = 0
                    var count_part = 0
                    for (m in 0 until t.length){
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
                if (ch == 0) {
                    result = part
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