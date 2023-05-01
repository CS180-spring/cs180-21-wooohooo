#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

int main()
{
    // this file creates a JSON object
    json j;
    j["Name"] = "Rickon Stark";
    j["Class Level"] = "Senior";
    j["Current Classes"] = ["CS141", "CS180", "CS166", "CS167"];
    j["Student ID"] = 862381111;

    j["Name"] = "Jon Snow";
    j["Class Level"] = "Junior";
    j["Current Classes"] = ["CS130", "CS165", "CS166", "CS010B"];
    j["Student ID"] = 862171711;
    
    j["Name"] = "Rickon Stark";
    j["Class Level"] = "Senior";
    j["Current Classes"] = ["CS110", "Math120", "CS141"];
    j["Student ID"] = 862718278;

    // write the JSON object to a file
    std::ofstream o("test.json");
    o << j;
    o.close();

    std::cout << "File created successfully." << std::endl;

    return 0;
}
