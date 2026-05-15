#include <iostream>
#include <map>
#include <vector>
#include <cstdint>
using namespace std;
int main(){    
    vector<uint8_t> k;
    int keyLength;
    cout << "Введите длину ключа: ";
    cin >> keyLength;
    cout << "Введите элементы ключа (через пробел): ";
    for (int i = 0; i < keyLength; i++) {
        int n;
        cin >> n; 
        k.push_back(static_cast<uint8_t>(n)); //оператор явного приведения типов
    }
    vector<uint8_t> s;    
    for (int i = 0; i < 256; i++){
        s.push_back(i);
    }
    
    int j = 0;
    for (int i = 0; i < 256; i++){
        j = (j + s[i] + k[i % k.size()]) % 256;
        swap(s[i],s[j]);
    }
    int n;
    cout << "Введите ваше N: ";
    cin >> n;
    int i = 0;
    for (int step = 0; step < n; step++){
        i = (i + 1) % 256;
        j = (j + s[i]) % 256;
        swap(s[i],s[j]);
        int t = ((s[i] + s[j])%256);
        int k_byte = s[t];
        cout << static_cast<int>(k_byte) << " ";
    }
    return 0;
}                  