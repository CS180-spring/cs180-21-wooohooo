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

void saveStudentsToJSON(const vector<Student>& students) {
    // 创建一个Document对象
    Document document;
    document.SetObject();

    // 创建一个Value对象来存储所有学生信息
    Value studentsJson(kArrayType);

    // 将所有学生信息添加到Value对象中
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

    // 将studentsJson添加到Document对象中
    document.AddMember("students", studentsJson, document.GetAllocator());

    // 创建一个StringBuffer对象
    StringBuffer buffer;

    // 创建一个Writer对象，将StringBuffer对象传递给它
    Writer<StringBuffer> writer(buffer);

    // 将Document对象写入StringBuffer对象
    document.Accept(writer);

    // 将StringBuffer对象的内容写入文件
    ofstream ofs("students.json");
    ofs << buffer.GetString();
    ofs.close();
}



Student inputStudentInfo(vector<Student>& students) {
    int id, status, level, year, month, day;
    string name, major;
    cout << "Please enter student id: ";
    cin >> id;
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
    
    cout << "Please enter student major: ";
    cin >> major;
    

    
    Student newStudent(id, name, year, month, day, status, level, major);
    
    students.push_back(newStudent);
        
    return newStudent;
}


#endif /* input_h */
