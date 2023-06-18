#include <iostream>
#include "read_int_value.h"
#include "is_prime.h"
#include "next_prime.h"
#include "factorial.h"
#include "fibonacci.h"
#include "print_binary.h"
#include "hex_to_decimal.h"
#include "is_sequention_right.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	// 1 
	/*int number;
	cout << "Введите целое число: ";
	cin >> number;
	bool result = is_prime(number);

	cout << "Число " << (is_prime(number) ? " простое." : " не является простым.");*/

	// 2
	/*read_int_value();*/

	// 3-4
	/*auto first_prime = next_prime();
	auto second_prime = next_prime();
	auto third_prime = next_prime();
	auto fourth_prime = next_prime();

	std::cout << first_prime << ", " << second_prime << ", " << third_prime << ", " << fourth_prime << ", " << std::endl;

	reset_prime();

	std::cout << next_prime() << std::endl;*/

	// 5
	/*auto f = factorial(18);

	std::cout << f << std::endl;*/

	// 6
	/*unsigned long long fibonacciNumber = fibonacci(50);
	std::cout << fibonacciNumber << std::endl;*/

	// 7
	/*print_binary(255);*/

	// 8
	/*hex_to_decimal("FF");*/

	// 9
	/*string sequention;
	cout << "Введите скобочную последовательность: ";
	cin >> sequention;
	cout << "Последовательность" << (is_sequention_right(sequention) ? " верная!" : " неверная!");*/
	
	return 0;
}