//
//  print.h
//  180project
//
//  Created by Hanlin Zha on 5/7/23.
//

#ifndef print_h
#define print_h

#include <iostream>
#include <vector>
#include <string>
#include "input.h"

using namespace std;

void printStudentInfo(const Student& student) {
    cout << "Student ID: " << student.getId() << endl;
    cout << "Name: " << student.getName() << endl;
    cout << "Birthday: " << student.getYear() << "." << student.getMonth() << "." << student.getDay() << endl;
    cout << "Status: ";
    if(student.getStatus() == 0){
        cout << "Good Standing" << endl;;
    }
    if(student.getStatus() == 1) {
        cout << "Academic Probation" << endl;
    }
    if(student.getStatus() == 2){
        cout << "Disqualified Status" << endl;
    }
    cout << "Level: ";
    if(student.getLevel() == 0){
        cout << "Undergraduate" << endl;;
    }
    if(student.getLevel() == 1) {
        cout << "Graduate" << endl;
    }
    cout << "Major: " << student.getMajor() << endl;
}

#endif /* print_h */
