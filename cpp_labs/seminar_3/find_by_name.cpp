#include <string>
#include <iostream>
#include "phone_directory_unit.h"


void find_by_name(
	TPhoneDirectoryUnit* first_directory_unit_pointer, 
	int phone_directory_length, 
	string name_to_find) {
	for (int i = 0; i < phone_directory_length; i++)
	{
		string current_unit_name{ (first_directory_unit_pointer + i)->name };

		if (current_unit_name == name_to_find)
		{
			cout << "Найдено совпадение по имени "
				<< name_to_find << ": \n"
				<< (first_directory_unit_pointer + i)->name
				<< " - "
				<< (first_directory_unit_pointer + i)->phone_number
				<< " - "
				<< (first_directory_unit_pointer + i)->email;
		}
	}
}