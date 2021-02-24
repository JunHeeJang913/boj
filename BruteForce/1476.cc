#include <iostream>
#include <string>

using namespace std;
const int E = 15, S = 28, M = 19;

int main(void){
    int year = 1;
    int earth, sun, moon;
    cin >> earth >> sun >> moon;
    while(true){
        if((year-earth) % E == 0 && (year-sun) % S == 0 && (year-moon) % M == 0){
            break;
        }
        ++year;
    }
    cout << year;
}