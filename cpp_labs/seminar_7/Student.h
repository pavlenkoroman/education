//
// Created by romap on 18.06.2023.
//

#ifndef SEMINAR_7_STUDENT_H
#define SEMINAR_7_STUDENT_H


#include <string>
#include <vector>

using namespace std;

class Student {
private:
    string first_name;
    string last_name;
    int birth_year;
    double average_grade;
    vector<int> grades;

public:
    Student(string first, string last, int year)
            : first_name(first), last_name(last), birth_year(year), average_grade(0.0) {}

    void set_first_name(string first) {
        first_name = first;
    }

    void set_last_name(string last) {
        last_name = last;
    }

    void set_birth_year(int year) {
        birth_year = year;
    }

    void add_grade(int grade) {
        grades.push_back(grade);
        recalculateAverageGrade();
    }

    static Student find_best_student(const vector<Student>& students) {
        double highestAverageGrade = 0.0;
        Student bestStudent("", "", 0);

        for (const auto& student : students) {
            if (student.get_average_grade() > highestAverageGrade) {
                highestAverageGrade = student.get_average_grade();
                bestStudent = student;
            }
        }

        return bestStudent;
    }

    std::string get_first_name() const {
        return first_name;
    }

    std::string get_last_name() const {
        return last_name;
    }

    int get_birth_year() const {
        return birth_year;
    }

    double get_average_grade() const {
        return average_grade;
    }

private:
    void recalculateAverageGrade() {
        int sum = 0;
        for (const auto& grade : grades) {
            sum += grade;
        }

        average_grade = static_cast<double>(sum) / grades.size();
    }
};


#endif //SEMINAR_7_STUDENT_H
