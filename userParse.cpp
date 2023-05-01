#include <iostream>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <string>
using namespace std;

int main(){
    // get data from file and parse
    ifstream file("userdata.json");
    Json::Value userinfo;
    Json::Reader reader;
    reader.parse(file, userinfo);

    cout << "The user data are:\n" << userinfo << endl;

    // show all data
    cout << "Name: " << userinfo["Name"] << endl;
    cout << "University: " << userinfo["UC"] << endl;
    cout << "Year of student: " << userinfo["Year"] << endl;
    cout << "Major: " << userinfo["Major"] << endl;

    return 0;
}

