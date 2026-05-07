#include <iostream>
#include <string>

using namespace std;

int main(){
    string s,t;
    cout << "Введите строку S: " << endl;
    cin >> s;
    cout << "Введите строку T: " << endl;
    cin >> t;
    string result = "";
    
    for (int i = 0; i < s.length(); i++){
        for (int j = t.length(); i + j <= s.length(); j ++){
            string part = s.substr(i,j);
            string part_1 = part;
            int ch = 0;

            for (int k = 0; k < t.length(); k++){
                int count_t = 0;
                int count_part = 0;
                for (int m = 0; m < t.length(); m++){
                    if (t[m] == t[k]) count_t++;
                }    
                for (int m = 0; m < part.length(); m++){
                    if (part[m] == t[k]) count_part++; 
                }
                if (count_part < count_t) ch++;
            }
        }
    }   
    if (result == "") cout << "Не найдено" << endl;
    else cout << "Результат: " << result << endl;
    return 0;
}