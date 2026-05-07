print( "Введите строку S:")
s = input()
print( "Введите строку T:")
t = input()

result = ""

for i in range(len(s)):
    for j in range(1, len(s) - i + 1):
        part = s[i : i + j]
        ch = 0
        for k in range(len(t)):
            count_in_t = t.count(t[k])
            count_in_part = part.count(t[k])
            if count_in_part >= count_in_t:
                ch += 1

        if ch >= len(t):
             if result == "" or len(part) < len(result):
                result = part

if result == "":
    print("Не найдено")
else:
    print(result) 