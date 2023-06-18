#include <iostream>
#include <chrono>
#define PI 3.14159

#define DEBUG

#pragma pack(push, 1) // устанавливаем выравнивание в 1 байт

struct MyStruct {
	char a;
	int b;
	double c;
};

#pragma pack(pop) // восстанавливаем предыдущее выравнивание

#pragma optimize("", on) // отключаем все оптимизации


using namespace std;

#ifdef RELEASE
	#error "Задание 6!"
#endif

int main()
{
	setlocale(LC_ALL, "ru");

#if defined DEBUG
	cout << "======= DEBUG MODE =======" << endl;
#else
	cout << "======= RELEASE MODE =======" << endl;
#pragma warning "4 задание"
#endif

	// 1
	/*double r;
	cout << "Введите радиус круга для вычисления его площади: ";
	cin >> r;

	cout << "Площадь круга: " << PI * r * r << endl;*/

	// 3 
	/*cout << "Размер структуры с выравниванием: " << sizeof(MyStruct) << " bytes" << endl;
	return 0;*/

	// 5

	const int size = 1000000;
	int* arr = new int[size];

	auto start = chrono::high_resolution_clock::now();

	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;

	cout << "Время некоторой операции: " << elapsed.count() << " секунд." << endl;

	delete[] arr;
}

