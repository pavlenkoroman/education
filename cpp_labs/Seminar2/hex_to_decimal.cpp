#include <iostream>
#include <string>

using namespace std;

void hex_to_decimal(string value) {
    string hex = value;
    int decimal = 0, base = 1;

    for (int i = hex.size() - 1; i >= 0; i--) {
        if (isdigit(hex[i])) {
            decimal += (hex[i] - '0') * base;
        }
        else {
            decimal += (hex[i] - 'A' + 10) * base;
        }
        base *= 16;
    }

    cout << "Десятичное число: " << decimal << endl;
}