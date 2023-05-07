//
//  Student.cpp
//  180project
//
//  Created by Hanlin Zha on 5/6/23.
//

#include "Person.hpp"
#include "Student.hpp"
#include <iostream>

using namespace std;

Student::Student(int id, string name, int year, int month, int day,
                 int status, int level, string major)
        : Person(id, name, year, month, day), m_status(status), m_level(level), m_major(major) {}
Student::~Student() {}

int Student::getStatus() const {
    return m_status;
}

int Student::getLevel() const {
    return m_level;
}

string Student::getMajor() const {
    return m_major;
}



