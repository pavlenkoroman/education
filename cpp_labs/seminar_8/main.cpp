#include <iostream>
#include <thread>
#include <mutex>
#include <random>

using namespace std;

mutex mtx;

void print_hello() {
    cout << "Hello, world!" << endl;
}

void calculate_square(int number) {
    int square = number * number;
    cout << "Квадрат числа " << number << ": " << square << endl;
}

void print_numbers(int start, int end) {
    for (int i = start; i <= end; ++i) {
        lock_guard<mutex> lock(mtx);
        cout << i << " ";
    }
}

void sum(int a, int b, int& result) {
    result = a + b;
}

void generate_random_number() {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 10);

    while (1) {
        int number = distribution(generator);
        cout << "Число: " << number << endl;
        this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int sum_array(const vector<int>& array) {
    int sum = 0;
    for (int num : array) {
        sum += num;
    }
    return sum;
}

int generate_random_number7() {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 10);
    return dist(mt);
}

void find_max_number(int& max_number) {
    for (int i = 0; i < 1000; ++i) {
        int number = generate_random_number7();
        if (number > max_number) {
            max_number = number;
        }
    }
}

void find_min_number(int& min_number) {
    for (int i = 0; i < 1000; ++i) {
        int number = generate_random_number7();
        if (number < min_number) {
            min_number = number;
        }
    }
}

void calculate_average(double& average) {
    int sum = 0;
    for (int i = 0; i < 1000; ++i) {
        int number = generate_random_number7();
        sum += number;
    }
    average = static_cast<double>(sum) / 1000;
}

void print_numbers_forward() {
    for (int i = 1; i <= 100; ++i) {
        cout << i << " ";
    }
    cout << endl;
}

void print_numbers_backward() {
    for (int i = 100; i >= 1; --i) {
        cout << i << " ";
    }
    cout << endl;
}

int multiply(int a, int b) {
    return a * b;
}

int generated_count = 0;

// Первый поток: генерация случайных чисел (задание 10)
void random_number_generator() {
    while (generated_count < 10) {
        int random_number = generate_random_number7();
        cout << "Сгенерировано число: " << random_number << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        generated_count++;
    }
}

// Второй поток: вывод сгенерированных чисел (задание 10)
void number_printer() {
    while (generated_count < 10) {
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    // 1

//    thread thread1(print_hello);
//
//    thread thread2(print_hello);
//
//    thread1.join();
//    thread2.join();

    // 2
//    thread thread_square(calculate_square, 10);
//
//    thread_square.join();

    // 3

//    const int num_threads = 5;
//    const int numbers_per_thread = 20;
//    thread threads[num_threads];
//
//    for (int i = 0; i < num_threads; ++i) {
//        int start = (i * numbers_per_thread) + 1;
//        int end = start + numbers_per_thread - 1;
//        threads[i] = thread(print_numbers, start, end);
//    }
//
//    for (auto &thread: threads) {
//        thread.join();
//    }

    // 4

//    int num1 = 5;
//    int num2 = 7;
//    int sum_result1 = 0;
//    int sum_result2 = 0;
//
//    thread thread1(sum, num1, num2, ref(sum_result1));
//
//    thread thread2(sum, num1, num2, ref(sum_result2));
//
//    thread1.join();
//    thread2.join();
//
//    cout << "Sum: " << sum_result1 + sum_result2 << endl;

    // 5

//    thread thread(generate_random_number);
//
//    cout << "Нажми Enter чтобы прервать программу." << endl;
//    cin.ignore();
//
//    // Прерывание работы потока
//    thread.detach();

    // 6
//    vector<int> array1 = {1, 2, 3, 4, 5};
//    vector<int> array2 = {6, 7, 8, 9, 10};
//
//    int result1 = 0;
//    int result2 = 0;
//
//    thread thread1([&]() {
//        result1 = sum_array(array1);
//    });
//
//    std::thread thread2([&]() {
//        result2 = sum_array(array2);
//    });
//
//    thread1.join();
//    thread2.join();
//
//    int totalSum = result1 + result2;
//    cout << "Total sum: " << totalSum << endl;

    // 7
//    int max_number = 0;
//    int min_number = 11;
//    double average = 0.0;
//
//    thread thread1(find_max_number, ref(max_number));
//    thread thread2(find_min_number, ref(min_number));
//    thread thread3(calculate_average, ref(average));
//
//    thread1.join();
//    thread2.join();
//    thread3.join();
//
//    cout << "Max number: " << max_number << endl;
//    cout << "Min number: " << min_number << endl;
//    cout << "Average: " << average << endl;

    // 8
//    thread thread_forward(print_numbers_forward);
//    thread thread_backward(print_numbers_backward);
//
//    thread_forward.join();
//    thread_backward.join();

    // 9
//    int result1, result2;
//
//    thread thread1([&]() {
//        result1 = multiply(2, 3);
//    });
//
//    thread thread2([&]() {
//        result2 = multiply(4, 5);
//    });
//
//    thread1.join();
//    thread2.join();
//
//    cout << "Произведение: " << result1 * result2 << endl;

    // 10

    thread generator_thread(random_number_generator);
    thread printer_thread(number_printer);

    generator_thread.join();
    printer_thread.join();

    return 0;
}
