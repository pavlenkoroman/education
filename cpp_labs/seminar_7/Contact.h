//
// Created by romap on 18.06.2023.
//

#ifndef SEMINAR_7_CONTACT_H
#define SEMINAR_7_CONTACT_H


#include <string>

using namespace std;

class Contact {
private:
    string first_name;
    string last_name;
    string phone_number;
    string email_address;

public:
    Contact(string first, string last,string phone, string email)
            : first_name(first), last_name(last), phone_number(phone), email_address(email) {}

    string get_first_name() const {
        return first_name;
    }

    string get_last_name() const {
        return last_name;
    }

    string get_phone_number() const {
        return phone_number;
    }

    string get_email_address() const {
        return email_address;
    }
};


#endif //SEMINAR_7_CONTACT_H
