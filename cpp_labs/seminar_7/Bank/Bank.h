//
// Created by romap on 18.06.2023.
//

#ifndef SEMINAR_7_BANK_H
#define SEMINAR_7_BANK_H

#include <vector>
#include "BankAccount.h"

using namespace std;

class Bank {
private:
    vector<BankAccount> accounts;

public:
    void open_account(string account_number, double initial_balance, double interest_rate) {
        BankAccount account(account_number, initial_balance, interest_rate);
        accounts.push_back(account);
    }

    void close_account(string account_number) {
        for (auto it = accounts.begin(); it != accounts.end(); ++it) {
            if (it->get_account_number() == account_number) {
                accounts.erase(it);
                break;
            }
        }
    }

    void transfer(string from_account, string to_account, double amount) {
        BankAccount *source_account = nullptr;
        BankAccount *destination_account = nullptr;

        for (auto &account: accounts) {
            if (account.get_account_number() == from_account) {
                source_account = &account;
            }
            if (account.get_account_number() == to_account) {
                destination_account = &account;
            }
        }

        if (source_account && destination_account) {
            source_account->withdraw(amount);
            destination_account->deposit(amount);
            cout << "Перевод выполнен." << endl;
        } else {
            cout << "Один или оба счета не найдены." << endl;
        }
    }

    const vector<BankAccount> &get_accounts() const {
        return accounts;
    };


#endif //SEMINAR_7_BANK_H
};