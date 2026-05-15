#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
cout << "Введите количество кандидатов: " << endl;
int n;
cin >> n;

cout << "Введите количество групп избирателей: "; // изменили формулировку
int g; // количество групп вместо k
cin >> g;

vector<int> counts; // новый вектор: сколько человек в каждой группе
int k = 0; // общее число избирателей, будем накапливать

vector<vector<int>> votes;
for (int i = 0; i < g; i++) { // перебираем группы, а не отдельных избирателей
cout << "Группа №" << i + 1 << " - количество человек: "; // новый ввод: размер группы
int cnt;
cin >> cnt;
counts.push_back(cnt); // запоминаем размер группы
k += cnt; // добавляем к общему числу избирателей

cout << "Группа №" << i + 1 << " - порядок кандидатов: "; // изменили формулировку
vector<int> single_votes;
for (int j = 0; j < n; j++) {
int id;
cin >> id;
single_votes.push_back(id);
        }
votes.push_back(single_votes);
    }

map<int, int> scores;
for (int i = 0; i < g; i++) { // перебираем группы
for (int j = 0; j < n; j++) {
int candidate = votes[i][j];
int points = (n - 1 - j);
scores[candidate] += points * counts[i]; // умножаем на размер группы
        }
    }
int winner_borda = -1;
int max_points = -1;
for (auto it = scores.begin(); it != scores.end(); ++it) {
if (it->second > max_points) {
max_points = it->second;
winner_borda = it->first;
        }
    }
cout << "По Борду: " << winner_borda << endl;
int condorcet_winner = -1;
for (auto itA = scores.begin(); itA != scores.end(); ++itA) {
int candA = itA->first;
bool wins_everyone = true;
for (auto itB = scores.begin(); itB != scores.end(); ++itB) {
int candB = itB->first;
if (candA == candB) continue;
int wins_in_pair = 0;
for (int i = 0; i < g; i++) { // перебираем группы
int posA = -1;
int posB = -1;
for (int j = 0; j < n; j++) {
if (votes[i][j] == candA) posA = j;
if (votes[i][j] == candB) posB = j;
                }
if (posA < posB) wins_in_pair += counts[i]; // прибавляем размер группы, а не 1
            }
if (wins_in_pair <= (k - wins_in_pair)) {
wins_everyone = false;
break;
            }
        }
if (wins_everyone) {
condorcet_winner = candA;
break;
        }
    }
if (condorcet_winner != -1) {
cout << "По Кондорсе: " << condorcet_winner << endl;
    } else {
cout << "По Кондорсе: не определён" << endl;
    }
return 0;
}