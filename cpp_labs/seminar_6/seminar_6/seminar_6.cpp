#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <chrono>

using namespace std;

bool is_palindrome(const string &str);

int main() {
    setlocale(LC_ALL, "Russian");

    // vector
    /*vector<int> v;
	int temp;

	for (size_t i = 1; i <= 5; i++)
	{
		cout << "¬ведите целое число " << i << ": " << endl;
		cin >> temp;

		v.push_back(temp);
	}

    bool swap = true;

    while (swap) {
        swap = false;
        for (size_t i = 0; i < v.size() - 1; i++) {
            if (v[i] > v[i + 1]) {
                v[i] += v[i + 1];
                v[i + 1] = v[i] - v[i + 1];
                v[i] -= v[i + 1];
                swap = true;
            }
        }
    }

    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }*/

    // string
//    cout << "¬ведите строку: ";
//    string input;
//    getline(cin, input);
//
//    cout << "—трока в обратном пор€дке: ";
//    reverse(input.begin(), input.end());
//    cout << input << endl;
//
//    if (is_palindrome(input)) {
//        cout << "¬веденна€ строка €вл€етс€ палиндромом." << endl;
//    } else {
//        cout << "¬веденна€ строка не €вл€етс€ палиндромом." << endl;
//    }

    // algorithm
    // 1
//    int n;
//    cout << "¬ведите количество элементов массива: ";
//
//    cin >> n;
//
//    vector<int> arr(n);
//
//    cout << "¬ведите элементы массива:" << endl;
//    for (int i = 0; i < n; ++i) {
//        cout << "Ёлемент " << to_string(i + 1) << " - ";
//        cin >> arr[i];
//    }
//
//    sort(arr.begin(), arr.end(), greater());
//
//    cout << "ќтсортированный массив в пор€дке убывани€:" << endl;
//    for (int element : arr) {
//        cout << element << " ";
//    }
//    cout << endl;

    // 2.
//    vector<int> numbers;
//
//    int n;
//    cout << "¬ведите количество чисел: ";
//    cin >> n;
//
//    cout << "¬ведите числа: " << endl;
//
//    for (int i = 0; i < n; ++i) {
//        cout << "Ёлемент " << to_string(i + 1) << " - ";
//        int number;
//        cin >> number;
//        numbers.push_back(number);
//    }
//
//    int count = 0;
//
//    for (int number: numbers) {
//        if (number > 5) {
//            count++;
//        }
//    }
//
//    cout << " оличество чисел, больших 5 - " << count << endl;

    // queue:
    // 1.
//    queue<int> queue;
//
//    int n;
//    cout << "¬ведите количество элементов в очереди: ";
//    cin >> n;
//
//    cout << "¬ведите элементы очереди: " << endl;
//    for (int i = 0; i < n; ++i) {
//        cout << "Ёлемент " << to_string(i + 1) << " - ";
//        int element;
//        cin >> element;
//        queue.push(element);
//    }
//
//    queue.pop();
//
//    cout << "Ќова€ очередь: " << endl;
//    while (!queue.empty()) {
//        cout << queue.front() << " ";
//        queue.pop();
//    }
//    cout << endl;

    // 2.
//    queue<int> queue;
//
//    int n;
//    cout << "¬ведите количество элементов в очереди: ";
//    cin >> n;
//
//    for (int i = 0; i < n; ++i) {
//        cout << "Ёлемент " << to_string(i + 1) << " - ";
//        int element;
//        cin >> element;
//        queue.push(element);
//    }
//
//    if (queue.empty()) {
//        cout << "ќчередь пуста." << endl;
//    } else {
//        cout << "ќчередь не пуста." << endl;
//    }

    // stack
    // 1.
//    stack<int> stack;
//
//    int n;
//    cout << "¬ведите количество элементов в стеке: ";
//    cin >> n;
//
//    cout << "¬ведите элементы стека:" << endl;
//    for (int i = 0; i < n; ++i) {
//        cout << "Ёлемент " << to_string(i + 1) << " - ";
//        int element;
//        cin >> element;
//        stack.push(element);
//    }
//
//    stack.pop();
//
//    cout << "Ќовый стек:" << endl;
//    while (!stack.empty()) {
//        cout << stack.top() << " ";
//        stack.pop();
//    }
//    cout << endl;

    // 2
//    stack<int> stack;
//
//    int n;
//    cout << "¬ведите количество элементов в стеке: ";
//    cin >> n;
//
//    cout << "¬ведите элементы стека:" << endl;
//    for (int i = 0; i < n; ++i) {
//        cout << "Ёлемент " << to_string(i + 1) << " - ";
//        int element;
//        cin >> element;
//        stack.push(element);
//    }
//
//    if (stack.empty()) {
//        cout << "—тек пуст." << endl;
//    } else {
//        cout << "—тек не пуст." << endl;
//    }

    // cmath
    // 1
//    double radius;
//    cout << "¬ведите радиус окружности: ";
//    cin >> radius;
//
//    double circumference = 2 * M_PI * radius;
//    double area = M_PI * pow(radius, 2);
//
//    cout << "ƒлина окружности: " << circumference << endl;
//    cout << "ѕлощадь окружности: " << area << endl;

    // 2
//    double number1, number2;
//    cout << "¬ведите первое число: ";
//    cin >> number1;
//
//    cout << "¬ведите второе число: ";
//    cin >> number2;
//
//    double average = (number1 + number2) / 2;
//
//    cout << "—реднее арифметическое: " << average << endl;

    // chrono
    const int SIZE = 1000000000;

    int* array = new int[SIZE];

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < SIZE; ++i) {
        array[i] = i;
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    cout << "¬рем€ заполнени€ массива: " << duration.count() << " мс" << endl;

    delete[] array;

    return 0;
}

bool is_palindrome(const string &str) {
    string reversed_string = str;
    reverse(reversed_string.begin(), reversed_string.end());
    return str == reversed_string;
}