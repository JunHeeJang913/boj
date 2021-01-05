#include <iostream>
#include <cstring>

const int MOD=1000000000;

using namespace std;

int cache[101][10];

int lookForStairDigit(int n,int x){
    //base case
    if(n<=1){
        if(x==0) return 0;
        else return 1;
    }
    //memoization
    int& ret = cache[n][x];
    if(ret != -1) return ret;

    if(x == 0){
        return ret = lookForStairDigit(n-1, 1) % MOD;
    }else if(x == 9){
        return ret = lookForStairDigit(n-1, 8) % MOD;
    }else{
        return ret = (lookForStairDigit(n-1, x-1) % MOD)+(lookForStairDigit(n-1, x+1) % MOD);
    }
}

//n자리 수 계단 수 개수.
int lookForStair(int n){
    int numOfStair=0;

    for(int i=0;i<10;++i)
        numOfStair = (numOfStair + lookForStairDigit(n,i)) % MOD;

    return numOfStair;
}

int main(void){
    int N;
    cin>>N;

    memset(cache, -1, sizeof(cache));
    int result = lookForStair(N);

    cout<<result;

    return 0;
}