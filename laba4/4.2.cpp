#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    ranlux24_base engine(random_device{}());
    uniform_int_distribution<int> dist(150, 300);

    cout << "Введите ваше N (>=10): ";
    int n;
    cin >> n;

    vector<int> arr;
    arr.reserve(n);
    for(int i = 0; i < n; i++){
        arr.push_back(dist(engine));
    }


    cout << "Исходный массив: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    int best_start = 0, best_len = 1;
    int cur_start = 0, cur_len = 1;

    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i-1]){      
            cur_len++;
        } else {
            cur_start = i;
            cur_len = 1;
        }
        if(cur_len > best_len){
            best_len = cur_len;
            best_start = cur_start;
        }
    }
    vector<int> result(arr.begin() + best_start, arr.begin() + best_start + best_len);

    cout << "Длина самой длинной убывающей последовательности: " << best_len << endl;
    cout << "Элементы: ";
    for(int x : result) cout << x << " ";
    cout << endl;
    int summ = 0;
    for (int x = 0; x < arr.size(); x++){
        summ += arr[x];
    }
    cout << "Среднее арифмитеческое: " << (summ / arr.size()) << endl; 
    vector <int> small_sr_arifmet; 
    for(int x : arr){
        if (x < (summ / arr.size())){
            small_sr_arifmet.push_back(x);
        } 
    }
    cout << "Элементы, которые меньше среднего арифметического значения: ";
    for (int x : small_sr_arifmet){
         cout << x << " ";
    }
    cout << endl;
    int arr1 = arr[0];
    int arr2 = arr[1];
    for(int i = 0; i < (arr.size() - 2); i++){
        arr[i] = arr[i+2];
    }
    arr[n-2] = arr1;
    arr[n-1] = arr2;
    cout << "модифицированный массив из пункта 1, путем сдвига влево на 2 позиции: ";
    for(int x:arr){
        cout << x << " ";
    }
    uniform_int_distribution<int> dist2(100, 120);
    vector<int> arr_2;
    cout << endl;
    cout << "Введите ваше P (>=20): ";
    int p;
    cin >> p;
    arr_2.reserve(p);
    for(int i = 0; i < p; i++){
        arr_2.push_back(dist2(engine));
    }
    sort(arr_2.begin(), arr_2.end(), greater<int>());
    cout << "Массив 2 : ";
    for(int x : arr_2){
        cout << x << " "; 
    }
    map<int,int> arr_2_1;
    for (int x : arr_2){
        arr_2_1[x]++;
    }
    int max_count = 0;
    int max_chislo = 0;
    for(auto pair : arr_2_1){
        if (pair.second > max_count){
            max_count = pair.second;
            max_chislo = pair.first;
        }
    }
    cout << endl;
    cout << "Число: " << max_chislo << ", повторяется: " << max_count << " раз";
    return 0;
}