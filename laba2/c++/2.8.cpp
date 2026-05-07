#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cout << "Введите количество встреч: ";
    cin >> n;
    cout << "Введите время начала и окончания каждой встречи (формат: start end):" << endl;
    vector<pair<int, pair<int, int>>> meetings;
    for (int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        meetings.push_back({end, {start, i}});
    }
    
    sort(meetings.begin(), meetings.end());
    
    vector<int> result;
    int count = 0;
    int last_end = -1;
    
    for (int i = 0; i < n; i++){
        if (meetings[i].second.first >= last_end){
            count++;
            last_end = meetings[i].first;
            result.push_back(meetings[i].second.second);
        }
    }
    
    cout << "Количество выбранных встреч: " << count << endl;
    cout << "Номера выбранных встреч: ";
    for (int i = 0; i < result.size(); i++){
        cout << result[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}