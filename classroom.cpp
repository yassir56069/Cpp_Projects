#include <iostream>
#include <string>
#include "classroom.h"
using namespace std;

int main(){
    menu(); 
    cout << "Closing.. " << endl; //program closing since menu stops running
    return 0;
}

void menu(){
    int choice;
    while (choice !=3 ){
        cout << "[Menu]+---" << endl;
        cout << "[1] Fill Classroom." << endl;
        cout << "[2] Display Classroom." << endl;
        cout << "[3] Close Program." << endl;
        cout << "Choice: "; cin >> choice;
        cout << endl << endl;

        switch (choice){
            case 1:
                fillClassroom();
                break;
            case 2:
                dispClassroom();
                break;
        }
    }
}

string name_prompt( int count ) {
    cout << "Enter First Name Of Person " << count + 1 << " : "; cin >> classA[count].fName; 
    cout << "Enter Last Name Of Person " << count + 1 << " : "; cin >> classA[count].lName; 
    cout << endl << endl;
    string temp_fName = classA[count].fName;
    string temp_fullName = temp_fName.append(classA[count].lName);
    return temp_fullName;
}

void fillClassroom( int up_to ){ 
    for (int i = 0 ; i < up_to ; i++ ){
        classA[i].fullName = name_prompt(i);
        while (classA[i].fullName.length() > name_limit) {
            cout << "Full Name too long.." << endl;
            classA[i].fullName = name_prompt(i);
        }
    }
} 

void dispClassroom( int up_to ){
    for (int i = 0; i < up_to ; i++){
        cout << "[" << i + 1 << "] " << "| First Name: " << classA[i].fName << " Last Name: " << classA[i].lName <<
            " Full Name: " << classA[i].fullName << endl;
    }
    cout << endl << endl;
}