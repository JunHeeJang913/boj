#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<int> s;
int cache[300];

int maxStair(int cur){
    //base case;
    if(cur == 0) return cache[cur] = s[cur];
    if(cur == 1) return cache[cur] = s[cur-1] + s[cur];
    if(cur == 2) return cache[cur] = max(s[cur-2]+s[cur], s[cur-1] + s[cur]);
    //memoization;
    int & ret = cache[cur];
    if(ret != -1) return ret;
    ret = max((maxStair(cur-2)+s[cur]), (maxStair(cur - 3) + s[cur-1] + s[cur]));
    return ret;
}

int main(void){
    cin >> n;

    //sequence initailization;
    s.reserve(n);
    for(int i = 0; i < n; ++i){
        int input;
        cin>> input;
        s.push_back(input);
    }

    memset(cache, -1, sizeof(cache));
    cout<< maxStair(n-1);
}