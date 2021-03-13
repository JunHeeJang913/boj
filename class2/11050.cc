#include <iostream>

using namespace std;

int factorial(int n){
    if(n <= 1) return 1;
    return factorial(n-1) * n;
}

int getBiCoefficient(int n, int k){
    return factorial(n) / (factorial(k) * factorial(n-k));
}
/*
TODO:   another solution
int combination(int n, int r){
    if(n == r || r == 0) return 1;
    return c(n-1, r-1) + c(n-1, r);
}
*/

int main(void){
    int n, k; cin >> n >> k;

    cout << getBiCoefficient(n,k);

    return 0;
}