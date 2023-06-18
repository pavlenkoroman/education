#pragma once
#include <string>
#include <vector>

using namespace std;

struct recipe {
    int subitem_count; // количество компонентов для сборки
    vector<string> subitems; // список компонентов
    int creation_cost; // стоимость создания
};