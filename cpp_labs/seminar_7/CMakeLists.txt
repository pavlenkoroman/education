cmake_minimum_required(VERSION 3.25)
project(seminar_7)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(seminar_7
        Fraction.cpp
        Fraction.h
        seminar_7.cpp Car.h Figures/Circle.h Figures/Rectangle.h Figures/Triangle.h Student.cpp Student.h Contact.cpp Contact.h PhoneBook.cpp PhoneBook.h Bank/BankAccount.cpp Bank/BankAccount.h Bank/Bank.cpp Bank/Bank.h Players/Player.cpp Players/Player.h Players/Warrior.cpp Players/Warrior.h Players/Mage.cpp Players/Mage.h Players/Archer.cpp Players/Archer.h Games/Game.cpp Games/Game.h Games/RPG.cpp Games/RPG.h Games/Shooter.cpp Games/Shooter.h)
