#include <iostream>
#include <cstring>

using namespace std;

const int DIV = 1000000000;
//TODO: 답의 범위에 항상 유의하자.
long long cache[201][201];  //[n][k]

//0부터 n까지의 정수 k개를 더해서 그 합이 n이 되는 경우의 수를 DIV로 나눈 나머지를 반환한다. 
long long numOfSum(int n, int k){
    //base case
    if(k == 1) return 1;
    //memoization
    long long& ret = cache[n][k];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i <= n; ++i){
        ret += (numOfSum(i, k-1) % DIV);
        ret %= DIV;
        //TODO:나머지끼리의 합이 DIV보다 커질 수 있음을 기억하자.
    }
    return ret;
}

int main(void){
    int n, k;
    cin >> n >> k;
    memset(cache, -1, sizeof(cache));
    cout << numOfSum(n,k);
}