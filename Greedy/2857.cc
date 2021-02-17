#include <iostream>

using namespace std;

int main(void){
    int female, male, intern;
    cin >> female >> male >> intern;

    int team = 0;
    while(true){
        if(intern <= ((female - 2) + (male - 1)) && female >= 2 && male >= 1){
            female -= 2; male -= 1; ++team;
        } else break;
    }
    cout << team;

    return 0;
}