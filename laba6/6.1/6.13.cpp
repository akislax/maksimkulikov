#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib> // Нужен для std::system
#include <ctime>

// Размеры игрового поля
const int WIDTH = 60;
const int HEIGHT = 20;

struct Point {
    int r, c;
};

// Универсальная жесткая очистка экрана для любой ОС
void clearScreen() {
#ifdef _WIN32
    std::system("cls");   // Очистка для Windows
#else
    std::system("clear"); // Очистка для Linux и macOS
#endif
}

// Подсчет живых соседей на ограниченной плоскости
int countNeighbors(const std::vector<std::vector<int>>& grid, int r, int c) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            
            int nr = r + i;
            int nc = c + j;
            
            if (nr >= 0 && nr < HEIGHT && nc >= 0 && nc < WIDTH) {
                count += grid[nr][nc];
            }
        }
    }
    return count;
}

// Расчет следующего поколения
std::vector<std::vector<int>> updateGrid(const std::vector<std::vector<int>>& grid) {
    std::vector<std::vector<int>> nextGrid(HEIGHT, std::vector<int>(WIDTH, 0));
    
    for (int r = 0; r < HEIGHT; ++r) {
        for (int c = 0; c < WIDTH; ++c) {
            int neighbors = countNeighbors(grid, r, c);
            
            if (grid[r][c] == 1) {
                if (neighbors == 2 || neighbors == 3) {
                    nextGrid[r][c] = 1;
                }
            } else {
                if (neighbors == 3) {
                    nextGrid[r][c] = 1;
                }
            }
        }
    }
    return nextGrid;
}

// Отрисовка поля
void printGrid(const std::vector<std::vector<int>>& grid) {
    clearScreen(); // Стираем абсолютно всё, что было на экране
    
    std::string output = "";
    for (int r = 0; r < HEIGHT; ++r) {
        for (int c = 0; c < WIDTH; ++c) {
            output += (grid[r][c] ? "O " : ". ");
        }
        output += "\n";
    }
    std::cout << output;
    std::cout << "Для выхода нажмите Ctrl+C\n";
}

void insertPattern(std::vector<std::vector<int>>& grid, const std::vector<Point>& pattern, int offsetR, int offsetC) {
    for (const auto& p : pattern) {
        int nr = p.r + offsetR;
        int nc = p.c + offsetC;
        if (nr >= 0 && nr < HEIGHT && nc >= 0 && nc < WIDTH) {
            grid[nr][nc] = 1;
        }
    }
}

int main() {
    std::setlocale(LC_ALL, "Russian");
    
    std::cout << "=== ИГРА «ЖИЗНЬ» НА C++ ===\n";
    std::cout << "1. Glider (Планер)\n";
    std::cout << "2. Lightweight Spaceship (LWSS)\n";
    std::cout << "3. Middleweight Spaceship (MWSS)\n";
    std::cout << "4. Heavyweight Spaceship (HWSS)\n";
    std::cout << "5. Queen Bee Shuttle (Челнок)\n";
    std::cout << "6. Случайная колония (Рандом)\n";
    std::cout << "===========================\n";
    std::cout << "Выбери цифру (1-6): ";
    
    int choice;
    std::cin >> choice;
    
    std::vector<std::vector<int>> grid(HEIGHT, std::vector<int>(WIDTH, 0));
    
    // Фигуры
    std::vector<Point> glider = {{0, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};
    std::vector<Point> lwss = {{0, 1}, {0, 4}, {1, 0}, {2, 0}, {2, 4}, {3, 0}, {3, 1}, {3, 2}, {3, 3}};
    std::vector<Point> mwss = {{0, 3}, {1, 1}, {1, 5}, {2, 0}, {3, 0}, {3, 5}, {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}};
    std::vector<Point> hwss = {{0, 3}, {0, 4}, {1, 1}, {1, 6}, {2, 0}, {3, 0}, {3, 6}, {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}};
    std::vector<Point> queenBee = {
        {5, 0}, {5, 1}, {6, 0}, {6, 1}, 
        {5, 40}, {5, 41}, {6, 40}, {6, 41}, 
        {10, 12}, {11, 10}, {11, 12}, {12, 9}, {12, 12}, {13, 8}, {13, 12}, {14, 9}, {14, 12}, {15, 10}, {15, 12}, {16, 12}
    };

    if (choice == 1) insertPattern(grid, glider, 2, 2);
    else if (choice == 2) insertPattern(grid, lwss, 5, 5);
    else if (choice == 3) insertPattern(grid, mwss, 5, 5);
    else if (choice == 4) insertPattern(grid, hwss, 5, 5);
    else if (choice == 5) insertPattern(grid, queenBee, 0, 5);
    else {
        std::srand(std::time(nullptr));
        for (int r = 0; r < HEIGHT; ++r) {
            for (int c = 0; c < WIDTH; ++c) {
                grid[r][c] = (std::rand() % 100 < 25) ? 1 : 0;
            }
        }
    }

    // Запуск анимации
    while (true) {
        printGrid(grid);
        grid = updateGrid(grid);
        std::this_thread::sleep_for(std::chrono::milliseconds(150)); // Скорость кадров
    }

    return 0;
}