#pragma once
#include <vector>
#include <string>

struct one_Product {
    std::string name_Product = "";
    int count_Product = 0;
};

struct one_Place {
    int zona = 0;
    int small_House = 0;
    int vertical = 0;
    int shelf = 0;
};

extern std::vector<std::vector<std::vector<std::vector<one_Product>>>> house_Product;

void size_Place(int zona, int small_House, int vertical, int shelf);
one_Place read_Address(const std::string& address);

void execute_ADD();
void execute_REMOVE();
void execute_INFO();