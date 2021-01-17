#include <iostream>
#include <cstring>

using namespace std;

int n;

int lbs(int * cache1, int * cache2){
    int maxLength=0;
    for(int i = 0; i < n; ++i){
        int curIndex = i+1;
        int tempMax = (cache1[curIndex]) + (cache2[curIndex]) -1;
        maxLength = max(maxLength, tempMax);
    }
    return maxLength;
}
void lis(int * s, int * cache){
    for(int i = 0; i <  n; ++i){
        cache[i+1] = 1;
        for(int j = 0; j < i; ++j){
            if(s[j] < s[i])
                cache[i+1] = max(cache[i+1], cache[j+1]+1);    
        }
    }
}

int lds(int* s, int* cache, int start){
    int & ret = cache[start+1];
    if(ret != -1) return ret;
    ret = 1;
    for(int next = start+1; next < n; ++next)
        if(start == -1||s[start] > s[next])
            ret = max(ret, lds(s, cache, next)+1);
    return ret;
}

int main(void){
    int s[1000], cacheL[1001], cacheD[1001];
    
    cin>>n;

    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }
    memset(cacheL, -1, sizeof(cacheL)); memset(cacheD, -1, sizeof(cacheD));
    lis(s, cacheL); lds(s, cacheD, -1);
    
    cout<<lbs(cacheL, cacheD)<<endl;

    return 0;
}