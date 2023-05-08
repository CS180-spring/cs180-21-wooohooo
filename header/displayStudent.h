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
#include "print.h"

void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student information found.\n";
        return;
    }
    for (const Student& student : students) {
        printStudentInfo(student);
    }
}


#endif /* displayStudent_h */
