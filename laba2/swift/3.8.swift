import Foundation

var numbers: [Int] = []

print("Введите ваше N: ", terminator: "")

if let input = readLine(), let n = Int(input) {
    
    print("Введите ваши числа:")
    
    if let line = readLine() {
        let parts = line.split(separator: " ")
        
        for i in 0..<min(n, parts.count) {
            if let num = Int(parts[i]) {
                numbers.append(num)
            }
        }
    }

    var count = 0
    
    if numbers.count > 1 {
        for i in 1..<numbers.count {
            if numbers[i] == numbers[i-1] {
                count += 1
            }
        }
    }
    
    print("Количество чисел, равных предыдущему: \(count)")
}