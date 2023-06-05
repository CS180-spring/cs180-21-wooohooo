[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10815271&assignment_repo_type=AssignmentRepo)
# StudentDB

This project is a developer-focused data store system built with C++ and Qt, primarily designed for storing and managing student information. The system provides an intuitive user interface and useful features to help developers efficiently work with student data.

## Table of Contents
- [Authors](#authors)
- [Features](#features)

## Authors

- [Hanlin Zha](https://github.com/AozakiKoriko) - Development lead/software architect
- [Sihua Lin](https://github.com/Linsihua) - Quality assurance/testing lead
- [Zhikang Liu](https://github.com/zk652) - Data structure engineer
- [Xi Chen](https://github.com/xchen184) - Algorithm and performance specialist
- [Justin Bollmann](https://github.com/justinwbollmann) - User/programming interface engineer

## Features

1. User Registration and Login
   - Developers can register an account and set a password for login and program access.

2. Folder Management
   - Each user can create their own folder to manage their personal files.
   - Folders are independent, and users cannot view or modify files in other users' folders.

3. View and Operate Files
   - Users can view all JSON files in their own folder.
   - Users can select a specific JSON file and view all keys and their corresponding values.
   - Users can add new JSON files and update the data within the files.
   - Users can delete unnecessary files to maintain an organized file list.

4. View and Edit Key-Value Pairs in JSON Files
   - Users can view all keys in a selected JSON file.
   - Users can add new keys and assign values to them.
   - Users can view all entries for a selected key and retrieve the corresponding information.
   - Users can add new entries to a selected key and add data to the JSON file.

5. Golbal Search
   - Users can search for entries by keywords and find entries that contain specific keywords.
   - Users can do further operations when located any specfic entries.

6. Edit and Delete JSON Entries
   - Users can edit selected JSON entries, add new data, or modify existing data.
   - Users can delete JSON entries that are no longer needed to keep the data updated and organized.

## Installation and Usage

1. Dowload and install Qt creator (https://www.qt.io/product/development-tools)
2. When launch Qt creator, clik "creat project".
3. In the pop-up window, select "Import Project" -> "Git Clone".
4. Copy repository URL at code<> of this page to the pop-up window of Qt creator and click continue.
5. Open "path.h" file in the "header".
6. Copy and paste your own file path to the "static QString folderPath".
7. Now you can run the program by click green play button.

## Technical Requirements

- C++ programming language
- Qt Creator development environment

## Notes

- This program is intended for use by developers and requires basic understanding of JSON data structure.
- It is recommended to back up important files before performing any deletion or modification operations.
- If you don't change the file path (step 5 and 6 in the installation), the programm will not run normally.
- When you input any JSON contants, you need use JSON data structure, for example: 
  If you want enter an entry like: 
  Name: Bob
  Age: 20
  You will required to input {"Name": "Bob", "Age", "20"}
- In case an entry cannot be edited or deleted because it cannot be accurately located, please create a unique identification like ID, phone number, SSN, etc.

## Contributions

- If you encounter any bugs or have suggestions for improvement, please submit an issue or pull request.
- Contributions for feature enhancements and optimizations are welcome.
