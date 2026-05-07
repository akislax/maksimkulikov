
n_input = IO.gets("Введите N: ") |> String.trim()
n = String.to_integer(n_input)

# 2. Читаем строку с числами
IO.puts("Введите числа через пробел:")
input = IO.gets("")


numbers = input |>
  String.split() |>
  Enum.take(n) |>
  Enum.map(&String.to_integer/1)


count = numbers |>
  Enum.chunk_every(2, 1, :discard) |>
  Enum.count(fn [prev, current] -> prev == current end)


IO.puts("Количество чисел, равных предыдущему: #{count}")
