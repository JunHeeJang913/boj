#include <iostream>
#include <cstring>

using namespace std;

int cache[41]; 

// 중요한건 피보나치 수열의 값이 아니라 호출횟수

int fibonacci(int n)
{
    //base case;
    if(n == 0 || n == 1) return cache[n] = n;
    int & ret = cache[n];
    if(ret != -1) return ret;
    return ret = fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; cin >> T;
    for(int i = 0; i < T; ++i)
    {
        memset(cache, -1, sizeof(cache));
        int n; cin >> n;
        fibonacci(n);
        if(n == 0)
            cout << 1 << " " << 0 << '\n';
        else if(n == 1)
            cout << 0 << " " << 1 << '\n';
        else 
            cout << cache[n-1] << " " << cache[n] << '\n';
    }
}