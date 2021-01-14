#include <iostream>
#include <cstring>

using namespace std;

int n;
int s[1000], cache[1001];

int lds(int start){
    int & ret = cache[start+1];
    
    if(ret != -1) return ret;
    ret = 1;
    for(int next = start + 1; next < n; ++next){
        if(start == -1||s[start]>s[next])
            ret = max(ret, lds(next)+1);
    }
    return ret;
}

int main(void){
    cin>>n;
    memset(cache, -1, sizeof(cache));
    for(int i = 0; i < n ;++i){
        cin >> s[i];
    }   
    cout<<lds(-1)-1<<endl;

    return 0;
}