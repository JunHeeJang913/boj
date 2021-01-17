/*
FIXME: 무조건 큰 수를 취하는게 능사는 아님. 그렇다면 어떻게 해야할까?????
다 해봐야지 뭐, greedy 가 안되면 brute force 밖에 내가 할 줄 아는게 더있음???
*/
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int cache[100001];

int sqrtInt(int n){
    double sqrtFlt = sqrt(n);
    int ni = (int)floor(sqrtFlt);
    return ni;
}

int cntSquareSum(int n){
    //base case;
    if(n < 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(n == 3) return 3;

    //memoization
    int & ret = cache[n];
    if(ret != -1) return ret;

    ret = n;
    for(int i = sqrtInt(n); 0 < i; --i){
        ret = min(cntSquareSum(n-i*i)+1, ret);
    }
    return ret;
}

int main(void){
    int N;
    cin >> N;

    memset(cache, -1, sizeof(cache));
    cout<< cntSquareSum(N);
}