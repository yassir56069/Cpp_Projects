#include <iostream>
#include <string>
#include <chrono>
#include "num_sys.h"
using namespace std::chrono;

/*
    _##__
    #_#__
    __#__
    __#__
    _###_

    _###_
    #___#
    ___#_
    __#__
    #####

    ####_
    ____#
    ####_
    ____#
    ####_

    ___#_
    _#_#_
    #__#_
    #####
    ___#_

    #####
    #____
    #####
    ____#
    #####

    _####
    #____
    ####_
    #___#
    _###_

    #####
    ____#
    __#__
    __#__
    _#___

    _###_
    #___#
    _###_
    #___#
    _###_

    _###_
    #___#
    _####
    ____#
    _###_

    _###_
    #___#
    #___#
    #___#
    _###_
*/

void w_screen(int value = 0);

int main() {
    auto start = high_resolution_clock::now();
    w_screen(0);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    int b[10]={1,2,3,4,5,6,7,8,9};
    for(int c=0; c < 10; c++){
        if (b[2] == 0){
            cout << "empty";
        } else {cout << "taken";}
    }
    cout << "Run Time: "<< duration.count() / 1000 << "microseconds" << endl;
    return 0;
}



void w_screen(int value){
    int letter_num = 0;
    string rows[1] = {
        "01110 10001 10001 10001 01110"
    };
    for (int i = 0; i < 1000; i++ ){
        letter_num = 0;
        while(letter_num < 5){
            if (letter_num == 0) { cout << "this"; } 
            else if (letter_num > 1) { cout << "this"; }
            cout << rows[letter_num] << endl;
            letter_num ++;
        }
    }
}
