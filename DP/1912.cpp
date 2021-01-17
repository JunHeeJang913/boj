#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
//FIXME: 종만북 p.117~읽으세요 이 멍청한 놈아!


// int continuousSum(int end){
//     //base case;
//     if(end == 0) return cache[end] = s[end];
    
//     //memoization
//     int & ret = cache[end];
//     if(ret != NEGINF) return ret;
//     if(continuousSum(end-1) >= 0)
//         ret = continuousSum(end-1) + s[end];
//     else
//         ret = s[end];
    
//     return ret;    
// }

int main(void){
    int n;
    cin >> n;
    
    vector<int> s;
    //i번째 수로 끝나는 수열의 최대 연속합.
    int cache[100000];
    const int NEGINF = -100000000;
    
    s.reserve(n);
    for(int i = 0; i < n;++i){
        int input;
        cin >> input;
        s.push_back(input);
    }

    
    memset(cache, NEGINF, sizeof(cache));
    
    cache[0] = s[0];
    for(int i = 1; i < n; ++i){
        if(cache[i-1] > 0)
            cache[i] = cache[i-1] + s[i];
        else cache[i] = s[i];
    }

    int max=NEGINF;
    for(int i = 0; i < n; ++i){
        if(max < cache[i]) max = cache[i];
    }

    cout << max;
}