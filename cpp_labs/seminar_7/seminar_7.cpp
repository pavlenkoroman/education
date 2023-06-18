#include <iostream>
#include "Fraction.h"
#include "Car.h"
#include "Figures/Circle.h"
#include "Figures/Rectangle.h"
#include "Figures/Triangle.h"
#include "Student.h"
#include "PhoneBook.h"
#include "Bank/Bank.h"
#include "Players/Warrior.h"
#include "Players/Mage.h"
#include "Players/Archer.h"
#include "Games/RPG.h"
#include "Games/Shooter.h"


int main() {
    setlocale(LC_ALL, "Russian");

    // 1

    Fraction fraction1(2, 6);
    Fraction fraction2(3, 12);

    Fraction sum = fraction1.add(fraction2);
    cout << "Сумма: ";
    sum.print();

    Fraction difference = fraction1.subtract(fraction2);
    cout << "Разность: ";
    difference.print();

    Fraction product = fraction1.multiply(fraction2);
    cout << "Произведение: ";
    product.print();

    Fraction quotient = fraction1.divide(fraction2);
    cout << "Частное: ";
    quotient.print();

    fraction1.reduce();
    cout << "Дробь 1 после сокращения: ";
    fraction1.print();

    fraction2.reduce();
    cout << "Дробь 2 после сокращения: ";
    fraction2.print();

    // 2

    Car car("Toyota", "Supra", 2022, "Бензин");
    car.print_info();

    car.set_brand("Honda");
    car.set_model("Accord");
    car.set_year(2021);
    car.set_engine_type("Гибрид");
    car.print_info();

    car.refuel(50.0);
    car.move(100.0);

    // 3

    Circle circle(5.0);
    cout << "Круг: Периметр = " << circle.get_perimeter() << ", Площадь = " << circle.get_area() << endl;

    Rectangle rectangle(4.0, 6.0);
    cout << "Прямоугольник: Периметр = " << rectangle.get_perimeter() << ", Площадь = " << rectangle.get_area() << endl;

    Triangle triangle(3.0, 4.0, 5.0);
    cout << "Треугольник: Периметр = " << triangle.get_perimeter() << ", Площадь = " << triangle.get_area() << endl;

    // 4

    Student student1("Вадим", "Усков", 2003);
    Student student2("Павленко", "Роман", 2002);
    Student student3("Павленко", "Александр", 2002);

    student1.add_grade(4);
    student1.add_grade(5);
    student1.add_grade(3);

    student2.add_grade(5);
    student2.add_grade(4);
    student2.add_grade(4);

    student3.add_grade(5);
    student3.add_grade(5);
    student3.add_grade(5);

    cout << "Студент 1: " << student1.get_first_name() << " " << student1.get_last_name()
         << ", Год рождения: " << student1.get_birth_year()
         << ", Средний балл: " << student1.get_average_grade() << endl;

    cout << "Студент 2: " << student2.get_first_name() << " " << student2.get_last_name()
         << ", Год рождения: " << student2.get_birth_year()
         << ", Средний балл: " << student2.get_average_grade() << endl;

    cout << "Студент 3: " << student3.get_first_name() << " " << student3.get_last_name()
         << ", Год рождения: " << student3.get_birth_year()
         << ", Средний балл: " << student3.get_average_grade() << endl;

    vector<Student> students = {student1, student2, student3};
    Student bestStudent = Student::find_best_student(students);
    cout << "Лучший студент: " << bestStudent.get_first_name() << " " << bestStudent.get_last_name()
         << ", Средний балл: " << bestStudent.get_average_grade() << endl;

    // 5

    PhoneBook phone_book;

    Contact contact1("John", "John", "+123456789", "john@example.com");
    phone_book.add_contact(contact1);

    Contact contact2("Richard", "Richard", "+987654321", "richard@example.com");
    phone_book.add_contact(contact2);

    Contact contact3("Rick", "Rick", "+444444444", "rick@example.com");
    phone_book.add_contact(contact3);

    string first_name, last_name;
    cout << "Введите имя контакта для поиска: ";
    cin >> first_name;
    cout << "Введите фамилию контакта для поиска: ";
    cin >> last_name;

    Contact found_contact = phone_book.find_contact(first_name, last_name);

    if (found_contact.get_first_name() != "") {
        cout << "Найден контакт:" << endl;
        cout << "Имя: " << found_contact.get_first_name() << endl;
        cout << "Фамилия: " << found_contact.get_last_name() << endl;
        cout << "Телефон: " << found_contact.get_phone_number() << endl;
        cout << "Email: " << found_contact.get_email_address() << endl;
    } else {
        cout << "Контакт не найден." << endl;
    }

    // 6

    Bank bank;

    bank.open_account("1234567890", 1000.0, 2.5);
    bank.open_account("9876543210", 5000.0, 3.0);

    cout << "Перевод средств:" << endl;
    bank.transfer("1234567890", "9876543210", 500.0);

    cout << "Информация о счетах:" << endl;
    for (const auto &account: bank.get_accounts()) {
        cout << "Номер счета: " << account.get_account_number() << endl;
        cout << "Баланс: " << account.get_balance() << endl;
        cout << "Процентная ставка: " << account.get_interest_rate() << endl;
        cout << endl;
    }

    bank.close_account("1234567890");
    bank.close_account("9876543210");

    // 7

    Warrior warrior("Воин", 100, 20, 10);
    Mage mage("Маг", 80, 30, 5);
    Archer archer("Лучник", 90, 15, 8);

    warrior.attack_player(mage);
    mage.cast_spell(warrior);
    archer.shoot_arrow(mage);

    // 8

    RPG rpg("Divinity Original Sin 2");
    Shooter shooter("Doom Eternal");

    rpg.start_game();
    shooter.start_game();

    rpg.display_game_state();
    shooter.display_game_state();

    rpg.finish_game();
    shooter.finish_game();

    rpg.display_game_state();
    shooter.display_game_state();

    return 0;
}
