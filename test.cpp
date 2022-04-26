#include <iostream>
#include <string>
using namespace std;

const int name_limit = 16; const int array_size = 3; 

string fName = "[Not Given]", lName = "[Not Given]";
string name_prompt( int count );
string  fullName[array_size];

void fill_array( int up_to = array_size );
void display_array();
void change_name(); int array_val; 


int main(){ 
    fill_array();
    change_name();
    display_array();
    return 0;
}


string name_prompt( int count ) {
    cout << "Enter First Name Of Person " << count + 1 << " : "; cin >> fName; 
    cout << "Enter Last Name Of Person " << count + 1 << " : "; cin >> lName; 
    cout << endl << endl;
    string temp_fullName = fName.append(lName);
    return temp_fullName;
}

void fill_array( int up_to = array_size ){
    for (int i = 0; i < up_to ; i++){
        fullName[i] = name_prompt(i);

        while (fullName[i].length() > name_limit) {
            cout << "Full Name too long.." << endl;
            fullName[i] = name_prompt(i);
        }
    }
}

void display_array(){
    for (int i = 0; i < array_size; i++) {
        cout << "[" << i + 1 << "] " << fullName[i] << endl;
    }
}

void change_name() {
    display_array();
    cout << "enter array value to change: "; cin >> array_val;
    fullName[ array_val - 1] = name_prompt( array_val - 1 );
}
