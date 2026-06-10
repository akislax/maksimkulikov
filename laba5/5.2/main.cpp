#include <iostream>
#include <string>
#include <vector>
#include "5.2.h"

int main() {
    std::cout << "Введите количество окон: ";
    int num_windows;
    if (!(std::cin >> num_windows) || num_windows <= 0) return 0;

    std::vector<visit_Ill> windows(num_windows);
    int id = 1;
    for (auto& w : windows) { w.number_Window = id++; w.time_Window = 0; }

    std::vector<one_Ill> patients;
    std::string command;
    while (std::cin >> command) {
        if (command == "ENQUEUE") {
            int t; std::cin >> t;
            std::cout << ENQUEUE(t, patients) << std::endl;
        } else if (command == "DISTRIBUTE") {
            DISTRIBUTE(patients, windows);
            for (auto& w : windows) {
                std::cout << "Окно " << w.number_Window << " (" << w.time_Window << " минут): ";
                for (size_t i = 0; i < w.tallon_Ill.size(); ++i) {
                    if (i > 0) std::cout << ", ";
                    std::cout << w.tallon_Ill[i];
                }
                std::cout << std::endl;
            }
            patients.clear();
            for (auto& w : windows) { w.time_Window = 0; w.tallon_Ill.clear(); }
        }
    }
    return 0;
}