#include <iostream>
#include <string>
#include "5.1.h"

using namespace std;

int main(){
    int z, r, s, sh;
    cout << "Введите количество зон, стеллажей, секций и полок: ";
    cin >> z >> r >> s >> sh;
    size_Place(z, r, s, sh);

    while (true) {
        cout << "Введите вашу команду: ";
        string command;
        cin >> command;

        if (command == "EXIT") {
            break; 
        } 

        if (command == "ADD"){
            execute_ADD(); 
        }

        if (command == "REMOVE") { 
            execute_REMOVE();
        }

        if (command == "INFO") {
            execute_INFO(); 
        }
    } 

    return 0; 
}