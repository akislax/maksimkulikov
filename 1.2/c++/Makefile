CXX = g++
TARGET = mainout

all: $(TARGET)
	@echo "Проект собран. Выполните './$(TARGET)' для запуска."

$(TARGET): main.o
	@echo "Линковка"
	$(CXX) main.o -o $(TARGET)

main.o: main.s
	@echo "Ассемблирование"
	as main.s -o main.o

main.s: main.i
	@echo "Компиляция"
	$(CXX) -S main.i -o main.s

main.i: main.cpp
	@echo "Препроцессинг"
	$(CXX) -E main.cpp -o main.i
