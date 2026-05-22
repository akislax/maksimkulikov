#include <iostream>
#include <vector>
using namespace std;

// Изменили тип элементов вектора на long long
int bestMove(vector<long long>& a, int pos, int n, int m, int lastTake) {
    int limit = min(m, n - pos);

    long long bestSum = -1e18; // Сделали число меньше, чтобы не было переполнения int
    int bestK = -1;            // Изначально -1, чтобы зафиксировать первый же разрешенный ход
    long long curSum = 0;      // Заменили на long long

    for (int k = 1; k <= limit; k++) {
        curSum += a[pos + k - 1];

        if (k == lastTake) continue; //1 вариант 

        // Поменяли только это условие: если это первый разрешенный ход (bestK == -1) 
        // или нашли сумму больше (или равную при меньшем k)
        if (bestK == -1 || curSum > bestSum || (curSum == bestSum && k < bestK)) {
            bestSum = curSum;
            bestK = k;
        }
    }

    // Если абсолютно все ходы были запрещены, берем 1, чтобы игра не зависла
    if (bestK == -1) bestK = 1;

    return bestK;
}

int main() {
    int n, m;
    cout << "Введите n и m: "<< endl;
    cin >> n >> m;

    // Заменили int на long long для безопасного подсчета сумм
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long pavel = 0, vika = 0; // Заменили на long long
    int lastPavel = 0, lastVika = 0;

    int pos = 0;
    int turn = 0;

    while (pos < n) {
        int take;

        if (turn == 0)
            take = bestMove(a, pos, n, m, lastPavel);
        else
            take = bestMove(a, pos, n, m, lastVika);

        long long sum = 0; // Заменили на long long
        for (int i = 0; i < take; i++)
            sum += a[pos + i];

        if (turn == 0) {
            pavel += sum;
            lastPavel = take;
        } else {
            vika += sum;
            lastVika = take;
        }

        pos += take;
        turn = 1 - turn;
    }

    cout << (pavel > vika ? 1 : 0);
    return 0;
}