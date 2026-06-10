#include "5.2.h"
#include <iostream>

std::string ENQUEUE(int time_Visit, std::vector<one_Ill>& patients) {
    int number_Ill = patients.size() + 1;
    std::string talon_Ill = "T";
    if (number_Ill < 10)        talon_Ill += "00";
    else if (number_Ill < 100)  talon_Ill += "0";
    talon_Ill += std::to_string(number_Ill);
    one_Ill new_patient;
    new_patient.time_Visit = time_Visit;
    new_patient.tallon_Ill = talon_Ill;
    patients.push_back(new_patient);
    return talon_Ill;
}

void DISTRIBUTE(std::vector<one_Ill>& patients, std::vector<visit_Ill>& windows) {
    if (windows.empty()) return;
    std::vector<one_Ill> sorted = patients;
    std::stable_sort(sorted.begin(), sorted.end(),
        [](const one_Ill& a, const one_Ill& b) {
            return a.time_Visit > b.time_Visit;
        });
    for (auto& patient : sorted) {
        visit_Ill* best = &windows[0];
        for (auto& window : windows) {
            if (window.time_Window < best->time_Window ||
               (window.time_Window == best->time_Window &&
                window.number_Window < best->number_Window)) {
                best = &window;
            }
        }
        best->tallon_Ill.push_back(patient.tallon_Ill);
        best->time_Window += patient.time_Visit;
    }
    for (auto& window : windows) {
        std::sort(window.tallon_Ill.begin(), window.tallon_Ill.end());
    }
    std::sort(windows.begin(), windows.end(),
        [](const visit_Ill& a, const visit_Ill& b) {
            return a.tallon_Ill[0] < b.tallon_Ill[0];
        });
    for (size_t i = 0; i < windows.size(); ++i) {
        windows[i].number_Window = i + 1;
    }
}