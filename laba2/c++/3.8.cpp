#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> numbers;
    int temp;
    cout << "Введите ваше N: ";
    cin >> temp;
    cout << "Введите ваши числа:";
    for(int i = 0; i < temp; i++){
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    int count = 0;
    for (int i = 1; i < numbers.size(); i++){
        if (numbers[i] == numbers[i-1]){
            count++;
        }
    }
    cout << "Количество чисел, равных предыдущему: " << count << endl;
    return 0;
}