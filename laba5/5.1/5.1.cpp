#include "5.1.h"
#include <iostream>
#include <iomanip>

using namespace std;

std::vector<std::vector<std::vector<std::vector<one_Product>>>> house_Product;


int global_z = 0, global_r = 0, global_s = 0, global_sh = 0;
int global_total_capacity = 0, global_zone_capacity = 0;

void size_Place(int zona, int small_House, int vertical, int shelf){
    global_z = zona; global_r = small_House; global_s = vertical; global_sh = shelf;
    global_total_capacity = zona * small_House * vertical * shelf * 10;
    global_zone_capacity = small_House * vertical * shelf * 10;

    house_Product.resize(zona);
    for (int i = 0; i < zona; i++){
        house_Product[i].resize(small_House);
        for(int j = 0; j < small_House; j++){
            house_Product[i][j].resize(vertical);
            for(int k = 0; k < vertical; k++){
                house_Product[i][j][k].resize(shelf);
            }
        }
    }
}

one_Place read_Address(const std::string& address) {
    one_Place place;
    std::string z_str = address.substr(0, 1); 
    
    if (z_str == "А") place.zona = 0;
    else if (z_str == "Б") place.zona = 1;
    else if (z_str == "В") place.zona = 2;
    place.small_House = std::stoi(address.substr(1, 2)) - 1;
    place.vertical = (address[3] - '0') - 1;
    place.shelf = (address[4] - '0') - 1;
    
    return place;
}

void execute_ADD() {
    string name_Product;
    int count_Product;
    string adress;
    cin >> name_Product >> count_Product >> adress;
    one_Place place = read_Address(adress);
    string current_name = house_Product[place.zona][place.small_House][place.vertical][place.shelf].name_Product;

    if (current_name != "" && name_Product != current_name){
        cout << "Ошибка: Ячейка занята товаром " << current_name << endl;
    } else {
        if (house_Product[place.zona][place.small_House][place.vertical][place.shelf].count_Product + count_Product > 10){
            cout << "Ошибка: Превышена вместимость ячейки (максимум 10)" << endl;
        } else {
            house_Product[place.zona][place.small_House][place.vertical][place.shelf].name_Product = name_Product;
            house_Product[place.zona][place.small_House][place.vertical][place.shelf].count_Product += count_Product;
            cout << "Добавлено " << count_Product << " " << house_Product[place.zona][place.small_House][place.vertical][place.shelf].name_Product << " в " << adress << endl;
        }
    }      
}

void execute_REMOVE() {
    string name_Product;
    int count_Product;
    string adress;
    cin >> name_Product >> count_Product >> adress;
    one_Place place = read_Address(adress);
    string current_name = house_Product[place.zona][place.small_House][place.vertical][place.shelf].name_Product;
    int current_count = house_Product[place.zona][place.small_House][place.vertical][place.shelf].count_Product;

    if (name_Product != current_name){
        cout << "Ошибка: Товар " << name_Product << " не найден в ячейке " << adress << endl;
    } else {
        if (current_count < count_Product){
            cout << "Ошибка: Недостаточно товаров для удаления" << endl;
        } else {
            house_Product[place.zona][place.small_House][place.vertical][place.shelf].count_Product -= count_Product;
            cout << "Удалено " << count_Product << " " << current_name << " (остаток: " << house_Product[place.zona][place.small_House][place.vertical][place.shelf].count_Product << ")" << endl;
            
            if (house_Product[place.zona][place.small_House][place.vertical][place.shelf].count_Product == 0) {
                house_Product[place.zona][place.small_House][place.vertical][place.shelf].name_Product = "";
            }
        }
    }
}

void execute_INFO() {
    int global_total_products = 0;
    vector<int> zone_products(global_z, 0); 

    cout << fixed << setprecision(2);

    for (int zi = 0; zi < global_z; zi++) {
        for (int ri = 0; ri < global_r; ri++) {
            for (int si = 0; si < global_s; si++) {
                for (int shi = 0; shi < global_sh; shi++) {
                    int count = house_Product[zi][ri][si][shi].count_Product;
                    global_total_products += count;
                    zone_products[zi] += count;
                }
            }
        }
    }

    double total_percentage = ((double)global_total_products / global_total_capacity) * 100.0;
    cout << "Загруженность склада: " << total_percentage << " %" << endl;

    for (int zi = 0; zi < global_z; zi++) {
        char zone_letter = 'A' + zi;
        double zone_percentage = ((double)zone_products[zi] / global_zone_capacity) * 100.0;
        cout << "Загруженность зоны " << zone_letter << ": " << zone_percentage << " %" << endl;
    }

    cout << "Заполненные ячейки:" << endl;
    for (int zi = 0; zi < global_z; zi++) {
        for (int ri = 0; ri < global_r; ri++) {
            for (int si = 0; si < global_s; si++) {
                for (int shi = 0; shi < global_sh; shi++) {
                    if (house_Product[zi][ri][si][shi].name_Product != "") {
                        string shelf_str = (ri + 1 < 10) ? "0" + to_string(ri + 1) : to_string(ri + 1);
                        string addr = string(1, 'A' + zi) + shelf_str + to_string(si + 1) + to_string(shi + 1);
                        cout << addr << ": " << house_Product[zi][ri][si][shi].name_Product 
                             << " (" << house_Product[zi][ri][si][shi].count_Product << ")" << endl;
                    }
                }
            }
        }
    }

    cout << "Пустые ячейки:" << endl;
    bool is_first = true;
    for (int zi = 0; zi < global_z; zi++) {
        for (int ri = 0; ri < global_r; ri++) {
            for (int si = 0; si < global_s; si++) {
                for (int shi = 0; shi < global_sh; shi++) {
                    if (house_Product[zi][ri][si][shi].name_Product == "") {
                        if (!is_first) {
                            cout << ", ";
                            if ((ri * global_s * global_sh + si * global_sh + shi) % 15 == 0) cout << endl; 
                        }
                        string shelf_str = (ri + 1 < 10) ? "0" + to_string(ri + 1) : to_string(ri + 1);
                        string addr = string(1, 'A' + zi) + shelf_str + to_string(si + 1) + to_string(shi + 1);
                        cout << addr;
                        is_first = false;
                    }
                }
            }
        }
    }
    cout << endl; 
}