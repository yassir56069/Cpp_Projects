#ifndef classroom_h
#define classroom_h

#include <iostream>
#include <string>
using namespace std;void class_menu();

void class_menu();

extern const int class_size; extern const int name_limit; //Not recommended, but where?

string name_prompt( int count );

void fillClassroom( int up_to = class_size) ; void dispClassroom( int up_to = class_size); 

#endif