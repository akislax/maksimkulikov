#pragma once
#include <vector>
#include <string>
#include <algorithm>

struct visit_Ill {
    int number_Window;
    int time_Window;
    std::vector<std::string> tallon_Ill;
};

struct one_Ill {
    int time_Visit;
    std::string tallon_Ill;
};

std::string ENQUEUE(int time_Visit, std::vector<one_Ill>& patients);
void DISTRIBUTE(std::vector<one_Ill>& patients, std::vector<visit_Ill>& windows);