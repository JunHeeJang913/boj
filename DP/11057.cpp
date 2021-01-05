#include <iostream>
#include <cstring>
#define MOD 10007

using namespace std;

int cache[1001][10];

int ascNumDigit(int n,int x){
    //base case
    if(n<=1) return 1;

    //memoization
    int& ref = cache[n][x];
    if(ref!=-1) return ref;
    ref=0;
    for(int i = 0; i<=x; ++i){
        ref = (ref+ascNumDigit(n-1,i))%MOD;
    }
    return ref;
}

int ascNum(int n){
    int result=0;
    for(int i = 0; i < 10; ++i){
        result = (result%MOD+ascNumDigit(n, i)%MOD)%MOD;
    }
    return result;
}

int main(void){
    int N;
    cin>>N;

    memset(cache,-1,sizeof(cache));

    int result = ascNum(N);
    cout<<result<<endl;


    return 0;
}