#include <iostream>
#include <vector>

std::vector<int> sumOddandEven(std::vector<int> a) {
    int Esum = 0, Osum = 0, iter = sizeof(a)/sizeof(int);
    for ( int i ; i < iter ; i++) {
        if ( a[i] % 2 == 0 || a[i] == 0 ) {
            Esum += a[i];
        } else { Osum += a[i]; }
    }
    std::vector<int> x(2);
    x.push_back(Esum);
    x.push_back(Osum);
    
    return x;
}

int main(){
    std::vector<int> y(10);
    for( int i; i < 10; i++) {
        y.push_back(  rand() % 30 );
    }

    std::cout << "Res: " << y;

    return 0;
}


