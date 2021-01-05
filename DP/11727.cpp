#include <iostream>
#define MOD 10007

using namespace std;

//2*n 크기의 직사각형을 1*2 or 2*1 or 2*2로 채울 수 있는 방법의 수를 10007로 나눈 나머지를 출력한다.

int cache[1001];

//2xN 크기의 사각형을 타일로 덮는 방법을 반환한다.
//tiling(n)=tiling(n-1)+tiling(n-2)
int tiling(int width){
    //base case
    if(width<=1) return 1;

    //memoization
    int& ret = cache[width];
    if(ret != -1) return ret;
    return ret = (tiling(width-2)*2+tiling(width-1)) % MOD;
}

int main(void){
    int n;
    cin>>n;

    fill_n(cache,1001,-1);

    int result = tiling(n);

    cout<<result<<endl;

    return 0;
}