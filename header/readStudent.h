//
//  readStudent.h
//  180project
//
//  Created by Hanlin Zha on 5/6/23.
//

#ifndef readStudent_h
#define readStudent_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Student.hpp"
#include "document.h"
#include "writer.h"
#include "stringbuffer.h"

using namespace std;
using namespace rapidjson;

void readStudentsFromJSON(vector<Student>& students) {
    ifstream ifs("students.json");

    if (!ifs.is_open()) {
        cerr << "Error: failed to open students.json" << endl;
        return;
    }

    stringstream buffer;
    buffer << ifs.rdbuf();
    string jsonStr = buffer.str();

    Document document;
    document.Parse(jsonStr.c_str());

    if (!document.IsObject()) {
        cerr << "Error: invalid JSON format" << endl;
        return;
    }

    if (!document.HasMember("students")) {
        cerr << "Error: students field not found" << endl;
        return;
    }

    const Value& studentsJson = document["students"];
    if (!studentsJson.IsArray()) {
        cerr << "Error: students field is not an array" << endl;
        return;
    }

    for (const Value& studentJson : studentsJson.GetArray()) {
        if (!studentJson.IsObject()) {
            cerr << "Error: student info is not an object" << endl;
            continue;
        }
        
        if (!studentJson.HasMember("id") || !studentJson.HasMember("name")
            || !studentJson.HasMember("year") || !studentJson.HasMember("month")
            || !studentJson.HasMember("day") || !studentJson.HasMember("status")
            || !studentJson.HasMember("level") || !studentJson.HasMember("major")) {
            cerr << "Error: missing required fields in student info" << endl;
            continue;
        }
        
        int id = studentJson["id"].GetInt();
        string name = studentJson["name"].GetString();
        int year = studentJson["year"].GetInt();
        int month = studentJson["month"].GetInt();
        int day = studentJson["day"].GetInt();
        int status = studentJson["status"].GetInt();
        int level = studentJson["level"].GetInt();
        string major = studentJson["major"].GetString();

        Student student(id, name, year, month, day, status, level, major);
        students.push_back(student);
    }

    cout << "Read " << students.size() << " students from students.json" << endl;
}


#endif /* readStudent_h */
