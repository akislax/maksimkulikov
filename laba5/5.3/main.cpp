#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "5.3.h"

int main() {
    std::map<std::string, std::vector<std::string>> lines;
    std::map<std::string, std::vector<std::string>> stations;

    std::string cmd_str;

    while (std::cin >> cmd_str) {
    
        Command_Type cmd = Read_Command(cmd_str);

        switch (cmd) {
            case Command_Type::CREATE_METRO:
                Create_Metro(lines, stations);
                break;

            case Command_Type::METROS:
                Metros(lines);
                break;

            case Command_Type::METROS_IN_STOP:
                Metros_In_Stop(stations);
                break;

            case Command_Type::STOPS_IN_METRO:
                Stops_In_Metro(lines, stations);
                break;

            case Command_Type::UNKNOWN:
                std::cout << "Ошибка: Неизвестная команда" << std::endl;
                break;
        }
    }

    return 0;
}