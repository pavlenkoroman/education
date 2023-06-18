//
// Created by romap on 18.06.2023.
//

#ifndef SEMINAR_7_CAR_H
#define SEMINAR_7_CAR_H

#include <iostream>
#include <utility>

using namespace std;

class Car {
private:
    string brand;
    string model;
    int year;
    string engine_type;
    double fuel_level;

public:
    Car(string car_brand, string car_model, int car_year, string car_engine_type)
            : brand(car_brand), model(car_model), year(car_year), engine_type(car_engine_type), fuel_level(0.0) {}

    void set_brand(string car_brand) {
        brand = car_brand;
    }

    void set_model(string car_model) {
        model = car_model;
    }

    void set_year(int car_year) {
        year = car_year;
    }

    void set_engine_type(string car_engine_type) {
        engine_type = car_engine_type;
    }

    void refuel(double fuel_amount) {
        fuel_level += fuel_amount;
        cout << "Автомобиль заправлен. Текущий уровень топлива: " << fuel_level << " л" << endl;
    }

    void move(double distance) {
        double fuelConsumption = 10.0;

        double required_fuel = distance * fuelConsumption;
        if (required_fuel > fuel_level) {
            cout << "Недостаточно топлива для перемещения на указанное расстояние" << endl;
        } else {
            fuel_level -= required_fuel;
            cout << "Автомобиль перемещен на " << distance << " км. Остаток топлива: " << fuel_level << " л" << endl;
        }
    }

    void print_info() const {
        setlocale(LC_ALL, "Russian");

        cout << "Марка - " << brand << endl;
        cout << "Модель - " << model << endl;
        cout << "Год выпуска - " << year << endl;
        cout << "Тип двигателя - " << engine_type << endl;
        cout << "Количество топлива - " << fuel_level << " л." << endl;
    }
};


#endif //SEMINAR_7_CAR_H
