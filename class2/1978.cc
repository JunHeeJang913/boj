#include <iostream>

using namespace std;

bool isPrime(int n){
    if(n <= 1) return false;
    if(n == 2) return true;
    for(int i = 2; i*i <= n; ++i)
        if(n % i == 0) return false;
    return true;
}

int main(void){
    int n; cin >> n;
    
    int ret = 0;
    for(int i = 0; i < n; ++i){
        int num; cin >> num;
        if(isPrime(num)) ++ret;
    }
    cout << ret << endl;

    return 0;
}