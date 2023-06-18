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
    // ���������� � ������������� ���������� ����� ��� ������� �������
    //TPhoneDirectoryUnit phone_directory[max]{
    //	{ "�����", "112233", "email1@gmail.com" },
    //	{ "����", "445566", "email2@gmail.com" },
    //	{ "�������", "778899", "email3@gmail.com" },
    //	{ "���������", "102030", "email4@gmail.com" },
    //	{ "�������", "405060", "email5@gmail.com" }
    //};
    //TPhoneDirectoryUnit* first_unit_pointer = phone_directory; // ������ ���������� �����

    //find_by_name(first_unit_pointer, max, "���������");

    // 2
    unordered_map<std::string, Recipe> recipes;
    // ������������ ��������
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
    const Recipe& recipe = recipes.at(item);  // �������� ������ ��� ��������

    int total_cost = recipe.creation_cost;  // ��������� ��������� ����� ��������� �������� ������ ��������

    for (const std::string& subitem : recipe.subitems) {
        total_cost += calculate_cost(subitem, recipes);  // ���������� ������� ��������� ������� �����������
    }

    return total_cost;
}