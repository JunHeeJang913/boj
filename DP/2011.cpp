#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000;
int cache[5001];


long long numberCase(int pw, int n){
    //base case;
    if(1 <= pw && pw <= 10) return 1;
    if(11 <= pw && pw <= 26) return 2;
    //memoization
    //FIXME:
    int & ret = cache[10];
    if(ret != -1) return ret;
    if((pw % 10 == 0) && ((pw%10)%10 == 0 || (pw%10)%10 >= 3)) return 0;
    if(pw % 100 > 26) return ret = numberCase(pw/10,n);
    else return ret = numberCase(pw/10,n) + numberCase(pw/100,n);
}

int main(void){
    int pw;
    cin >> pw;
    static int password[5001];
    int n=0;
    for(int i = 1; pw > 0; pw /= 10, ++i){
        password[i] = pw % 10;
        ++n;
    }

    memset(cache, -1, sizeof(cache));
    cout << numberCase(pw, n);
}