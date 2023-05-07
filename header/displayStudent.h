//
//  displayStudent.h
//  180project
//
//  Created by Hanlin Zha on 5/6/23.
//

#ifndef displayStudent_h
#define displayStudent_h

#include "readStudent.h"
#include "input.h"

void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student information found.\n";
        return;
    }
    for (const Student& student : students) {
        cout << "Student ID: " << student.getId() << endl;
        cout << "Name: " << student.getName() << endl;
        cout << "Year of Birth: " << student.getYear() << endl;
        cout << "Month of Birth: " << student.getMonth() << endl;
        cout << "Day of Birth: " << student.getDay() << endl;
        cout << "Status: " << student.getStatus() << endl;
        cout << "Level: " << student.getLevel() << endl;
        cout << "Major: " << student.getMajor() << endl;
        cout << endl;
    }
}


#endif /* displayStudent_h */
