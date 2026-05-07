fun main() {
    println("Введите строку S: ")
    var s = readln().trim()
    println("Введите строку T: ")
    var t = readln().trim()
    var result = ""
    
    for (i in 0 until s.length) {
        for (j in t.length..s.length - i) {
            var part = s.substring(i, i + j)
            var part_1 = part
            var ch = 0

            for (k in 0 until t.length) {
                var count_t = 0
                var count_part = 0
                
                for (m in 0 until t.length) {
                    if (t[m] == t[k]) {
                        count_t++
                    }
                }
                for (m in 0 until part.length) {
                    if (part[m] == t[k]) {
                        count_part++
                    }
                }
                
                if (count_part < count_t) {
                    ch++
                }
            }
        
            if (ch == 0) {
                if (result == "" || part.length < result.length) {
                    result = part
                }
            }
        }
    }   
    
    if (result == "") {
        println("Не найдено")
    } else {
        println("Результат: $result")
    }
}