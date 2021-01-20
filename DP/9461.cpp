#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

long long cache[101];

long long wave(int n){
    //base case;
    if(1 <= n && n < 4) return 1;
    if(4 <= n && n < 6) return 2;
    //memoization
    long long & ret = cache[n];
    if(ret != -1) return ret;
    ret = wave(n-5) + wave(n-1);
    return ret;
}

int main(void){
    int T;
    cin >> T;
    memset(cache, -1, sizeof(cache));
    for(int i = 0; i < T; ++i){
        int N;
        cin >> N;
        //어차피 수열의 값은 동일하니 굳이 초기화할 이유가 없음.
        //memset(cache, -1, sizeof(cache));
        long long length = wave(N);
        cout << length << endl;
    }
}