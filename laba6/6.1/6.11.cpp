#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int M, N;
    cout << "Введите M: "; cin >> M;
    cout << "Введите N: "; cin >> N;

    vector<vector<int>> a(M, vector<int>(N));


    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            a[i][j] = rand() % 101;

    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }

    double total = 0;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            total += a[i][j];
    cout << "\nСреднее всей матрицы: " << total / (M * N) << endl;

   
    int bestRow = 0;
    double bestAvg = 0;

    for (int i = 0; i < M; i++) {
        double sum = 0;
        for (int j = 0; j < N; j++)
            sum += a[i][j];
        double avg = sum / N;
        cout << "Строка " << i << ": среднее = " << avg << endl;
        if (avg > bestAvg) {
            bestAvg = avg;
            bestRow = i;
        }
    }

    cout << "\nСтрока с наибольшим средним: " << bestRow << endl;

    return 0;
}