#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double xS = -5.0, xE = 5.0, dx = 0.5, y;
    int n;

    cout << "1. y = -0.5 * (x + 3)^2 + 2" << endl;
    cout << "2. y = -x - 1" << endl;
    cout << "3. y = sqrt(1 - (x + 2)^2)" << endl;
    cout << "4. y = -0.5 * x - 0.5" << endl;
    cout << "5. y = -1 - sqrt(1 - (x - 2)^2)" << endl;
    cout << "6. y = -x" << endl;
    cout << "7. y = 0.5 * (x - 3)^2 - 3" << endl;

    cout << "┌───────┬────────────┬────────────┐" << endl;
    cout << "│" << setw(6) << "N" << " │ " << setw(10) << "X" << " │ " << setw(10) << "Y" << " │" << endl;
    cout << "├───────┼────────────┼────────────┤" << endl;

    for (double x = xS; x <= xE + dx / 2; x += dx) {
        if (x >= -5 && x < -3) {
            y = -0.5 * pow(x + 3, 2) + 2;
            n = 1;
        } 
        else if (x >= -3 && x < -2) {
            y = -x - 1;
            n = 2;
        } 
        else if (x >= -2 && x < -1) {
            y = sqrt(1 - pow(x + 2, 2));
            n = 3;
        } 
        else if (x >= -1 && x < 1) {
            y = -0.5 * x - 0.5;
            n = 4;
        } 
        else if (x >= 1 && x < 2) {
            y = -1 - sqrt(1 - pow(x - 2, 2)); 
            n = 5;
        } 
        else if (x >= 2 && x < 3) {
            y = -x;
            n = 6;
        } 
        else {
            y = 0.5 * pow(x - 3, 2) - 3;
            n = 7;
        }

        cout << "│" << setw(6) << n << " │ " 
             << setw(10) << fixed << setprecision(2) << x << " │ " 
             << setw(10) << y << " │" << endl;
    }
    
    cout << "└───────┴────────────┴────────────┘" << endl;

    return 0;
}