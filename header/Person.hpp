//
//  Person.hpp
//  180project
//
//  Created by Hanlin Zha on 5/6/23.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Person {
public:
    Person(int id, string name, int year, int month, int day);
    virtual ~Person();

    int getId() const;
    string getName() const;
    int getYear() const;
    int getMonth() const;
    int getDay() const;

protected:
    int m_id;
    string m_name;
    int m_year;
    int m_month;
    int m_day;
};

#endif /* Person_hpp */
