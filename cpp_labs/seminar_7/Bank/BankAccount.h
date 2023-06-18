//
// Created by romap on 18.06.2023.
//

#ifndef SEMINAR_7_BANKACCOUNT_H
#define SEMINAR_7_BANKACCOUNT_H


#include <string>
#include <iostream>

using namespace std;

class BankAccount {
private:
    string account_number;
    double balance;
    double interest_rate;

public:
    BankAccount(string number, double initial_balance, double rate)
            : account_number(number), balance(initial_balance), interest_rate(rate) {}

    string get_account_number() const {
        return account_number;
    }

    double get_balance() const {
        return balance;
    }

    double get_interest_rate() const {
        return interest_rate;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Недостаточно средств на счете." << endl;
        }
    }

    void add_interest() {
        double interest = balance * interest_rate / 100;
        balance += interest;
    }
};


#endif //SEMINAR_7_BANKACCOUNT_H
