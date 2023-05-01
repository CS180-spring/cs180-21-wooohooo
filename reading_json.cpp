#include <iostream>
#include <fstream>
#include "json.hpp"


//this file reads the JSON file
using json = nlohmann::json;

int main()
{
    // read the JSON file into a JSON object
    std::ifstream i("test.json");
    json j;
    i >> j;
    i.close();

    // print the contents of the JSON object
    std::cout << "Name: " << j["name"] << std::endl;
    std::cout << "Class Level: " << j["Class Level"] << std::endl;
    std::cout << "Current Classes: " << j["Current Classes"] << std::endl;
    std::cout << "Student ID: " << j["Student ID"] << std::endl;

    return 0;
}