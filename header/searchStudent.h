//
//  searchStudent.h
//  180project
//
//  Created by Hanlin Zha on 5/7/23.
//

#ifndef searchStudent_h
#define searchStudent_h

#include <iostream>
#include <vector>
#include <string>
#include "input.h"
#include "print.h"

using namespace std;

void searchStudentByID(const vector<Student>& students, int id) {
    for (const Student& student : students) {
        if (student.getId() == id) {
            cout << "Student found:" << endl;
            printStudentInfo(student);
            return;
        }
    }
    cout << "Student not found." << endl;
}

#endif /* searchStudent_h */
