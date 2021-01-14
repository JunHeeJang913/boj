#include <iostream>
#include <cstring>

using namespace std;

int n;
int s[1000], cache[1001];

int lis(int start){
    int & ret = cache[start+1];

    if(ret != -1) return ret;

    ret = 1;
    for(int next = start+1; next < n; ++next)
        if(start == -1||s[start] < s[next])
            ret = max(ret, lis(next)+1);
    return ret;
}

int main(void){
        cin >> n;
        memset(cache, -1, sizeof(cache));
        for(int j = 0; j < n; ++j){
            cin>>s[j];
        }
        cout<<lis(-1)-1<<endl;
}