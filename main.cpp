#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void login();
void signUp();
void forgot();

int main(){
    int choice;
    cout << "Type 1: login\n";
    cout << "Type 2: sign up\n";
    cout << "Type 3: exit\n";
    cout << "Your choice:  ";
    // user choices
    cin >> choice;
    cout << endl;

    // information input
    switch(choice){
        case 1:
        login();
        break; 

        case 2:
        signUp();
        break;
            
        case 3:
        cout << "You have exited!";
        break;

        default:
        system("clear");
        cout << "Wrong action, type among these numbers: (1); (2); (3) \n";
        main();
    }

}


void login(){
    int temp;
    string username, password, id, code;
    system("clear");
    cout << "Please input your username and password \n";
    cout << "username: ";
    // input username
    cin >> username;
    cout << "password: ";
    // input password
    cin >> password;

    // check the information valid or invalid
    ifstream input("information.txt");
    while(input >> id >> code){
        if(id == username && code == password){
            temp = 1;
            system("clear");

        }
    }
    input.close();
    if(temp == 1){
        cout << " Welcome,  " << username << endl;
        main();
    }
    else{
        cout << "incorrect username or password, please check\n";
        main();
    }
}


void signUp(){
    string newUsername, newPassword, newId, newCode;
    system("clear");
    cout << "Please input your NEW username and NEW password \n";
    cout << "NEW username: ";
    // input NEW username
    cin >> newUsername;
    cout << "NEW password: ";
    // input NEW password
    cin >> newPassword;

    // save the new user information into .txt
    ofstream theFile("information.txt", ios::app);
    theFile << newUsername << ' ' << newPassword << endl;
    system("clear");
    cout << "signUp successful\n";
    main();

}

