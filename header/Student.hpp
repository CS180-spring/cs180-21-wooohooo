//
//  Student.hpp
//  180project
//
//  Created by Hanlin Zha on 5/6/23.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <string>
#include "Person.hpp"
#include <iostream>
using namespace std;

class Student : public Person {
public:
    Student(int id, string name, int year, int month, int day,
            int status, int level, string major);
    ~Student();

    int getStatus() const;
    int getLevel() const;
    string getMajor() const;

private:
    int m_status;
    int m_level;
    string m_major;
};

Student inputStudentInfo();

#endif /* Student_hpp */
