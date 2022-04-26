#ifndef classroom_h
#define classroom_h

#include <iostream>
#include <string>
using namespace std;

const int class_size = 5; const int name_limit = 16;

struct classroom {
    string fName, lName, fullName;
} classA[class_size];

string name_prompt( int count );

void fillClassroom( int up_to = class_size) ; void dispClassroom( int up_to = class_size); 
void menu();

#endif