#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int N;
    cout << "Введите N (больше 5): ";
    cin >> N;
    if (N <= 5) {
        cout << "N должно быть больше 5!" << endl;
        return 1;
    }

    vector<vector<int>> a(N, vector<int>(N));


    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            a[i][j] = rand() % 201 - 100;

    
    cout << "\nИсходная матрица:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }

    
    for (int j = 0; j < N; j++) {
        
        vector<int> col(N);
        for (int i = 0; i < N; i++)
            col[i] = a[i][j];

        
        if (j % 2 == 0)
            sort(col.begin(), col.end());
        else
            sort(col.begin(), col.end(), greater<int>());

        
        for (int i = 0; i < N; i++)
            a[i][j] = col[i];
    }

    
    cout << "\nМатрица после сортировки:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }

    return 0;
}