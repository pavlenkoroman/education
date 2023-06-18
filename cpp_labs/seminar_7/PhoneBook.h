//
// Created by romap on 18.06.2023.
//

#ifndef SEMINAR_7_PHONEBOOK_H
#define SEMINAR_7_PHONEBOOK_H

#include <iostream>
#include <vector>
#include "Contact.h"

using namespace std;

class PhoneBook {
private:
    vector<Contact> contacts;

public:
    void add_contact(const Contact &contact) {
        contacts.push_back(contact);
    }

    void remove_contact(string first_name, string last_name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->get_first_name() == first_name && it->get_last_name() == last_name) {
                contacts.erase(it);
                break;
            }
        }
    }

    Contact find_contact(const std::string &first_name, const std::string &last_name) {
        for (const auto &contact: contacts) {
            if (contact.get_first_name() == first_name && contact.get_last_name() == last_name) {
                return contact;
            }
        }

        return Contact("", "", "", "");
    };
};

#endif //SEMINAR_7_PHONEBOOK_H