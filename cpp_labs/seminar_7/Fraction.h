//
// Created by romap on 18.06.2023.
//

#ifndef SEMINAR_7_FRACTION_H
#define SEMINAR_7_FRACTION_H


#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    int find_nod(int a, int b) const {
        if (b == 0)
            return a;
        else
            return find_nod(b, a % b);
    }

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {}

    Fraction add(const Fraction& other) const {
        int result_num = numerator * other.denominator + other.numerator * denominator;
        int result_denom = denominator * other.denominator;
        return *new Fraction(result_num , result_denom);
    }

    Fraction subtract(const Fraction& other) const {
        int result_num = numerator * other.denominator - other.numerator * denominator;
        int result_denom = denominator * other.denominator;
        return *new Fraction(result_num, result_denom);
    }

    Fraction multiply(const Fraction& other) const {
        int result_num = numerator * other.numerator;
        int result_denom = denominator * other.denominator;
        return *new Fraction(result_num, result_denom);
    }

    Fraction divide(const Fraction& other) const {
        int result_num = numerator * other.denominator;
        int result_denom = denominator * other.numerator;
        return *new Fraction(result_num, result_denom);
    }

    void reduce() {
        int gcd = find_nod(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }
};


#endif //SEMINAR_7_FRACTION_H
