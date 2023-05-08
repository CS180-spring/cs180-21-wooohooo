//
//  input.h
//  180project
//
//  Created by Hanlin Zha on 5/6/23.
//

#ifndef input_h
#define input_h

#include <stdio.h>
#include <iostream>
#include <string>
#include "Student.hpp"
#include "document.h"
#include "writer.h"
#include "stringbuffer.h"
#include <fstream>

using namespace std;
using namespace rapidjson;

void returnToMainMenu() {
    cout << "Press 0 to return to main menu." << endl;
    while (true) {
        if (cin.get() == '0') {
            cin.ignore();
            //system("clear"); //  Linux
            //system("cls"); //  Windows
            return;
        }
    }
}

void saveStudentsToJSON(const vector<Student>& students) {
    Document document;
    document.SetObject();

    Value studentsJson(kArrayType);

    for (const Student& student : students) {
        Value studentJson(kObjectType);
        studentJson.AddMember("id", student.getId(), document.GetAllocator());
        studentJson.AddMember("name", Value(student.getName().c_str(), document.GetAllocator()), document.GetAllocator());
        studentJson.AddMember("year", student.getYear(), document.GetAllocator());
        studentJson.AddMember("month", student.getMonth(), document.GetAllocator());
        studentJson.AddMember("day", student.getDay(), document.GetAllocator());
        studentJson.AddMember("status", student.getStatus(), document.GetAllocator());
        studentJson.AddMember("level", student.getLevel(), document.GetAllocator());
        studentJson.AddMember("major", Value(student.getMajor().c_str(), document.GetAllocator()), document.GetAllocator());

        studentsJson.PushBack(studentJson, document.GetAllocator());
    }

    document.AddMember("students", studentsJson, document.GetAllocator());

    StringBuffer buffer;

    Writer<StringBuffer> writer(buffer);

    document.Accept(writer);

    ofstream ofs("students.json");
    ofs << buffer.GetString();
    ofs.close();
}

bool studentIdExists(const vector<Student>& students, int id) {
    for (const Student& student : students) {
        if (student.getId() == id) {
            return true;
        }
    }
    return false;
}


Student inputStudentInfo(vector<Student>& students) {
    int id, status, level, year, month, day;
    string name, major;
    while (true) {
            cout << "Please enter student id: ";
            cin >> id;

            if (studentIdExists(students, id)) {
                cout << "Student ID already exists. Please enter a different ID." << endl;
            } else {
                break;
            }
        }
    cout << "Please enter student name: ";
    cin >> name;
    cout << "Please enter student year of birth: ";
    cin >> year;
    cout << "Please enter student month of birth: ";
    cin >> month;
    cout << "Please enter student day of birth: ";
    cin >> day;
    
    while (true) {
            cout << "Please enter student status (0 for Good Standing , 1 for Academic Probation, 2 for Disqualified Status): ";
            cin >> status;
            if (status == 0 || status == 1 || status == 2) {
                break;
            } else {
                cout << "Invalid input! Please enter 0 for Good Standing , 1 for Academic Probation and 2 for Disqualified Status" << endl;
            }
        }
    
    while (true) {
            cout << "Please enter student level (0 for undergraduate, 1 for graduate): ";
            cin >> level;
            if (level == 0 || level == 1) {
                break;
            } else {
                cout << "Invalid input! Please enter 0 for undergraduate or 1 for graduate." << endl;
            }
        }
    cin.ignore();
    cout << "Please enter student major: ";
    getline(cin, major);
    

    
    Student newStudent(id, name, year, month, day, status, level, major);
    
    students.push_back(newStudent);
        
    return newStudent;
}

int getStudentIdFromUser() {
    int searchId;
    cout << "Enter the student ID you want to find: ";
    cin >> searchId;
    return searchId;
}

string getMajorFromUser() {
    string searchMajor;
    cout << "Enter the major you want to shows: ";
    cin.ignore();
    getline(cin, searchMajor);
    return searchMajor;
}



#endif /* input_h */
