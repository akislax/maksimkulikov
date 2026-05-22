#include <iostream>
#include <vector>
#include <ctime>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef cpp_int bigint;


bigint bin_Pow(bigint a, bigint n, bigint mod) {
    bigint res = 1;
    a %= mod;
    while (n > 0) {
        if (n % 2 != 0) res = (res * a) % mod;
        a = (a * a) % mod;
        n /= 2;
    }
    return res;
}

bigint gcd(bigint a, bigint b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

vector<bigint> resheto_Erotosfena(int limit) {
    vector<int> is_Prime(limit + 1, 1);
    is_Prime[0] = is_Prime[1] = 0;
    for (int i = 2; i * i <= limit; i++) {
        if (is_Prime[i]) {
            for (int j = i * i; j <= limit; j += i)
                is_Prime[j] = 0;
        }
    }
    vector<bigint> Primes;
    for (int i = 2; i <= limit; i++) {
        if (is_Prime[i]) Primes.push_back(i);
    }
    return Primes;
}

bigint generate_Candidate(int bits){ //генерация рандом чисел
    bigint num = 0;
    bit_set(num, 0); // у нас число может начаться с нуля и разрядность потеряется, поэтому самый левый бит должны сделать числом, чтобы сохранить разрядность
    bit_set(num, bits - 1);//у нас число состоит из битов и если мы сделаем самый правый бит 0, то число автоматически будет всегда нечетным, то есть простым 
    for(int i = 1; i < bits - 1;i++){
        if(rand() % 2 == 1){
            bit_set(num,i);
        }
    }
    return num;
}
bool fast_Filter(bigint candidate, const vector<bigint>& primes){ //быстрая проверка делится ли сгенирированное число на числа из решета
    for (bigint p : primes){
        if (candidate % p == 0) {
            return false;
        }
    }
    return true;
}

bool razlojenie_Mnojitel(bigint n, const vector<bigint>& primes, vector<bigint>& f_Mnojitel, bigint& F){
    bigint temp = n - 1;
    F = 1;
    f_Mnojitel.clear();
    for(bigint p : primes){
        if (temp % p == 0){
            f_Mnojitel.push_back(p);
        }
        while (temp % p == 0){
            temp /= p;
            F *= p;
        }
    }
    if (F * F > n){
        return true;
    }else{
        return false;
    }
}

bool pocklington_Test(bigint n, bigint F, const vector<bigint>& f_Mnojitel){
    for (bigint a = 2; a <= 100; a++){
        // Условие 1: a^(n-1) % n должно быть равно 1
        if (bin_Pow(a, n - 1, n) != 1) {
            continue; // Если не 1, то это 'a' нам не подходит, пробуем следующее
        }
    
        bool good_A = true;
        for (bigint p : f_Mnojitel) {
                bigint power = (n - 1) / p;
                bigint check_Pow = bin_Pow(a, power, n);
            
                // Нам нужен НОД(a^((n-1)/p) - 1, n). 
                // Чтобы не уйти в отрицательные числа при вычитании единицы, делаем так:
                bigint gcd_Res = gcd((check_Pow - 1 + n) % n, n); //как считали mod у нас же не может быть -число чтобы это избежать прибавляем n
                if (gcd_Res != 1) {
                    good_A = false; // НОД не равен 1, это 'a' провалилось
                    break; 
                }
            }
            // Если для текущего 'a' выполнены оба условия — число гарантированно простое!
            if (good_A) {
                return true; 
            }
    }
            return false; // Если перебрали кучу 'a' и ничего не подошло — число составное
}

int main(){
    // Шаг 1 методички: Построить таблицу простых чисел меньше 500
    vector<bigint> primes = resheto_Erotosfena(500);
    srand(time(0));
    
    cout << "Введите ваше bits" << endl;
    int bits;
    cin >> bits;
    
    // Массивы для хранения итоговой Таблицы 2 (исправлен регистр букв)
    vector<bigint> table_Candidates(10);
    vector<string> table_Results(10);
    vector<int> table_Rejected(10);
    
    // Шаг 3 методички: Построить 10 различных чисел-кандидатов
    for (int i = 0; i < 10; i++) {
        int rejected = 0; // Шаг 4 методички: Переменная rejected для каждого числа
        bigint candidate;
        bigint F;
        vector<bigint> f_Mnojitel;
        
        // Шаг 5 методички: Генерируем, пока не найдем число, прошедшее тест
        while (true) {
            // Шаг 2 методички: Генерация числа заданной разрядности bits
            candidate = generate_Candidate(bits);
            
            // Проверка быстрым фильтром
            if (!fast_Filter(candidate, primes)) {
                rejected++;
                continue;
            }
            
            // Проверка разложения n - 1
            if (!razlojenie_Mnojitel(candidate, primes, f_Mnojitel, F)) {
                rejected++;
                continue;
            }
            
            // Проверка тестом Поклингтона
            if (!pocklington_Test(candidate, F, f_Mnojitel)) {
                rejected++;
                continue;
            }
            
            // Число успешно прошло тест Поклингтона
            break;
        }
        
        //Дополнительная проверка этим же тестом для надежности t = 2.
        bool final_Check = pocklington_Test(candidate, F, f_Mnojitel);
        
        // Запоминаем результаты для вывода таблицы
        table_Candidates[i] = candidate;
        table_Results[i] = final_Check ? "true" : "false";
        table_Rejected[i] = rejected;
    }

    cout << "\nРезультаты выполнения тестов\n";
    cout << "------------------------------------------------------------------------------------------------------------------------\n";
    cout << "№\t\t\t| "; for(int i=0; i<10; i++) cout << i+1 << "\t| "; cout << "\n";
    cout << "------------------------------------------------------------------------------------------------------------------------\n";
    cout << "Простое число\t\t| "; for(int i=0; i<10; i++) cout << table_Candidates[i] << "\t| "; cout << "\n";
    cout << "------------------------------------------------------------------------------------------------------------------------\n";
    cout << "Результат проверки\t| "; for(int i=0; i<10; i++) cout << table_Results[i] << "\t| "; cout << "\n";
    cout << "------------------------------------------------------------------------------------------------------------------------\n";
    cout << "Количество отвергнутых\t| "; for(int i=0; i<10; i++) cout << table_Rejected[i] << "\t| "; cout << "\n";
    cout << "------------------------------------------------------------------------------------------------------------------------\n";

    return 0;
}