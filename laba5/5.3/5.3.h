#pragma once
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <iostream>

enum class Command_Type {
    CREATE_METRO,
    METROS_IN_STOP,
    STOPS_IN_METRO,
    METROS,
    UNKNOWN
};

Command_Type Read_Command(const std::string& cmd);
void Create_Metro(std::map<std::string, std::vector<std::string>>& lines,
                  std::map<std::string, std::vector<std::string>>& stations);
void Metros(const std::map<std::string, std::vector<std::string>>& lines);
void Metros_In_Stop(const std::map<std::string, std::vector<std::string>>& stations);
void Stops_In_Metro(const std::map<std::string, std::vector<std::string>>& lines,
                    const std::map<std::string, std::vector<std::string>>& stations);