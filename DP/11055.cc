#include <iostream>
#include <cstring>

using namespace std;

int n;
int cache[1000];
int s[1000];


int maxIs(void){
    int ret = 0;
    for(int i = 0; i< n; ++i){
        cache[i] = s[i];
        for(int j = 0; j <= i; ++j){
            if(s[j]<s[i] && cache[i] < cache[j]+s[i])
                cache[i] = cache[j] + s[i];
        }
        ret = max(ret, cache[i]);
    }
    return ret;
}

int main(void){
    cin>>n;
    for(int i = 0; i < n; ++i)
        cin>>s[i];
    memset(cache, -1, sizeof(cache));
    cout<< maxIs() << endl;
}