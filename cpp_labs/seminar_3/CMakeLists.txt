cmake_minimum_required(VERSION 3.25)
project(seminar_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(seminar_3
        find_by_name.cpp
        find_by_name.h
        phone_directory_unit.h
        recipe.h
        seminar_3.cpp
        TPhoneDirectoryUnit.cpp
        TPhoneDirectoryUnit.h)
