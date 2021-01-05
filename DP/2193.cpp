#include <iostream>
#include <cstring>

using namespace std;

long long cache[91][2];

long long subSolve(int n, bool x){
    //base case
    if(n==1){
        if(x==0) return 0;
        else return 1;
    }
    if(n==2){
        if(x==0) return 1;
        else return 0;
    }
    //memoization
    long long & ret = cache[n][x];

    if(ret!=-1) return ret;

    if(x==0){
        ret = subSolve(n-1, 0) + subSolve(n-1, 1);
    }else{
        ret = subSolve(n-1, 0);
    }
    return ret;
}

long long solve(int n){
    long long result = subSolve(n,0) + subSolve(n,1);

    return result;
}

int main(void){
    int N;
    cin>>N;
    memset(cache, -1, sizeof(cache));
    for(N=1;N<=90;++N)
    cout<<solve(N)<<endl;
    return 0;
}
/*
TODO:
    오답노트. 피보나치와 같은 상황임을 알 수 있다.
    + int보다 더 큰 정수형 필요.
*/