//
//  Person.cpp
//  180project
//
//  Created by Hanlin Zha on 5/6/23.
//

#include "Person.hpp"
#include <iostream>

using namespace std;

Person::Person(int id, string name, int year, int month, int day)
    : m_id(id), m_name(name), m_year(year), m_month(month), m_day(day) {}

Person::~Person() {}

int Person::getId() const {
    return m_id;
}

string Person::getName() const {
    return m_name;
}

int Person::getYear() const {
    return m_year;
}

int Person::getMonth() const {
    return m_month;
}

int Person::getDay() const {
    return m_day;
}
