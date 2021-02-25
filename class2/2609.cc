#include <iostream>

using namespace std;

int LCM(int a, int b, int d){
    return int(a*b/d);
}

int GCD(int a,int b){
    while(b > 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(void){
    int a, b; cin >> a >> b;
    int d = GCD(a, b);
    int m = LCM(a, b, d);

    cout << d << '\n' << m << endl;

    return 0;
}