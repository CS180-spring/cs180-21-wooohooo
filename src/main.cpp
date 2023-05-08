//
//  main.cpp
//  180project
//
//  Created by Hanlin Zha on 5/6/23.
//

#include <iostream>
#include "Student.hpp"
#include "input.h"
#include "readStudent.h"
#include "displayStudent.h"
#include "searchStudent.h"


using namespace std;

int main(int argc, const char * argv[]) {
    int choice;
    vector<Student> students;

    while (true) {
        cout << "--------------------------------------------------\n";
        cout << "Please choose an option:\n";
        cout << "1 - Input student information\n";
        cout << "2 - Read student information from JSON\n";
        cout << "3 - Save student information to JSON\n";
        cout << "4 - Display all students' information\n";
        cout << "5 - Search for a student by ID\n";
        cout << "0 - Exit program\n";
        cout << "--------------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Exiting program...\n";
                return 0;
            case 1:
                {
                Student newStudent = inputStudentInfo(students);
                cout << "New student information saved.\n";
                }
                break;
            case 2:
                readStudentsFromJSON(students);
                cout << "Students information readed from students.json\n";
                break;

            case 3:
                saveStudentsToJSON(students);
                cout << "Students information saved to students.json\n";
                break;
            case 4:
                displayAllStudents(students);
                break;
            case 5:
                {
                int searchId = getStudentIdFromUser();
                searchStudentByID(students, searchId);
                break;
                }
            default:
                cout << "Invalid choice!\n";
                break;
        }
    }

    return 0;
}









