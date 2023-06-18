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
        cout << "���������� ���������. ������� ������� �������: " << fuel_level << " �" << endl;
    }

    void move(double distance) {
        double fuelConsumption = 10.0;

        double required_fuel = distance * fuelConsumption;
        if (required_fuel > fuel_level) {
            cout << "������������ ������� ��� ����������� �� ��������� ����������" << endl;
        } else {
            fuel_level -= required_fuel;
            cout << "���������� ��������� �� " << distance << " ��. ������� �������: " << fuel_level << " �" << endl;
        }
    }

    void print_info() const {
        setlocale(LC_ALL, "Russian");

        cout << "����� - " << brand << endl;
        cout << "������ - " << model << endl;
        cout << "��� ������� - " << year << endl;
        cout << "��� ��������� - " << engine_type << endl;
        cout << "���������� ������� - " << fuel_level << " �." << endl;
    }
};


#endif //SEMINAR_7_CAR_H
