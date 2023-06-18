#include <iostream>
#include <string>
#include <unordered_map>
#include "phone_directory_unit.h"
#include "find_by_name.h"
#include "recipe.h"

#define max 5

using namespace std;

struct Recipe {
    int subitem_count;
    std::vector<std::string> subitems;
    int creation_cost;
};

int calculate_cost(const string& item, const std::unordered_map<string, Recipe>& recipes);

int main() {
    setlocale(LC_ALL, "Russian");

    // 1
    // объявление и инициализация телефонной книги как массива записей
    //TPhoneDirectoryUnit phone_directory[max]{
    //	{ "Роман", "112233", "email1@gmail.com" },
    //	{ "Олег", "445566", "email2@gmail.com" },
    //	{ "Дмитрий", "778899", "email3@gmail.com" },
    //	{ "Александр", "102030", "email4@gmail.com" },
    //	{ "Алексей", "405060", "email5@gmail.com" }
    //};
    //TPhoneDirectoryUnit* first_unit_pointer = phone_directory; // начало телефонной книги

    //find_by_name(first_unit_pointer, max, "Александр");

    // 2
    unordered_map<std::string, Recipe> recipes;
    // Элементарные предметы
    recipes["Coal"] = {0, {}, 2};
    recipes["IronOre"] = {0, {}, 3};
    recipes["Wood"] = {0, {}, 1};

    recipes["Grip"] = {1, {"Wood"}, 4};
    recipes["IronIngot"] = {2, {"Coal", "IronOre"}, 5};
    recipes["IronSword"] = {2, {"IronIngot", "Grip"}, 10};

    string item;
    cout << "Item name: ";
    cin >> item;

    int cost = calculate_cost(item, recipes);

    cout << "Item " << item << " cost: " << cost << std::endl;

    return 0;
}

int calculate_cost(const string& item, const std::unordered_map<string, Recipe>& recipes) {
    const Recipe& recipe = recipes.at(item);  // Получаем рецепт для предмета

    int total_cost = recipe.creation_cost;  // Начальная стоимость равна стоимости создания самого предмета

    for (const std::string& subitem : recipe.subitems) {
        total_cost += calculate_cost(subitem, recipes);  // Рекурсивно считаем стоимость каждого подпредмета
    }

    return total_cost;
}