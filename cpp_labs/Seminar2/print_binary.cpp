#include <iostream>

void print_binary(unsigned long long value) {
    unsigned long long decimal = value, remainder = 0, result = 0, base = 1;

    while (decimal > 0) {
        remainder = decimal % 2;
        result += remainder * base;
        decimal /= 2;
        base *= 10;
    }

    std::cout << "Двоичное число: " << result << std::endl;
}