#include "5.3.h"

Command_Type Read_Command(const std::string& cmd) {
    if (cmd == "CREATE_METRO")   return Command_Type::CREATE_METRO;
    if (cmd == "METROS_IN_STOP") return Command_Type::METROS_IN_STOP;
    if (cmd == "STOPS_IN_METRO") return Command_Type::STOPS_IN_METRO;
    if (cmd == "METROS")         return Command_Type::METROS;
    return Command_Type::UNKNOWN;
}

void Create_Metro(std::map<std::string, std::vector<std::string>>& lines,
                  std::map<std::string, std::vector<std::string>>& stations) {
    std::string line_Name;
    int n;
    std::cin >> line_Name >> n;

    if (line_Name.empty()) {
        std::cout << "Ошибка: Имя линии не может быть пустым" << std::endl;
        return;
    }

    
    std::string rest;
    std::getline(std::cin, rest);
    std::istringstream iss(rest);
    std::vector<std::string> line_Stations;
    std::string token;
    while (iss >> token) {
        line_Stations.push_back(token);
    }

    n = static_cast<int>(line_Stations.size());

    if (lines.count(line_Name)) {
        std::cout << "Ошибка: Линия " << line_Name << " уже существует" << std::endl;
        return;
    }

    if (n < 2) {
        std::cout << "Ошибка: Линия должна содержать минимум 2 станции" << std::endl;
        return;
    }

  
    std::set<std::string> unique_Check(line_Stations.begin(), line_Stations.end());
    if (unique_Check.size() != static_cast<size_t>(n)) {
        std::cout << "Ошибка: Линия " << line_Name
                  << " содержит повторяющиеся станции" << std::endl;
        return;
    }

    lines[line_Name] = line_Stations;
    for (const auto& station : line_Stations) {
        stations[station].push_back(line_Name);
    }
}

void Metros(const std::map<std::string, std::vector<std::string>>& lines) {
    if (lines.empty()) {
        std::cout << "Ошибка: Линии метро не найдены" << std::endl;
        return;
    }
    for (const auto& pair : lines) {
        std::cout << "Линия " << pair.first << ":";
        for (const auto& station : pair.second) {
            std::cout << " " << station;
        }
        std::cout << std::endl;
    }
}

void Metros_In_Stop(const std::map<std::string, std::vector<std::string>>& stations) {
    std::string station_Name;
    std::cin >> station_Name;

    if (stations.count(station_Name) == 0) {
        std::cout << "Ошибка: Станция " << station_Name << " не найдена" << std::endl;
        return;
    }

    std::cout << "Линии метро на станции " << station_Name << ":";
    for (const auto& line : stations.at(station_Name)) {
        std::cout << " " << line;
    }
    std::cout << std::endl;
}

void Stops_In_Metro(const std::map<std::string, std::vector<std::string>>& lines,
                    const std::map<std::string, std::vector<std::string>>& stations) {
    std::string line_Name;
    std::cin >> line_Name;

    if (lines.count(line_Name) == 0) {
        std::cout << "Ошибка: Линия " << line_Name << " не найдена" << std::endl;
        return;
    }

    for (const auto& station : lines.at(line_Name)) {
        std::cout << "Станция " << station << ":";
        if (stations.at(station).size() == 1) {
            std::cout << " нет пересадок" << std::endl;
        } else {
            std::cout << " пересадка на линии:";
            for (const auto& other_Line : stations.at(station)) {
                if (other_Line != line_Name) {
                    std::cout << " " << other_Line;
                }
            }
            std::cout << std::endl;
        }
    }
}