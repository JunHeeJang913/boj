#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int MOD = 1000000;
int n;
int cache[5001];
int password[5001];

int numOfDecoding(void){
    cache[0] = 1; //0
    for (int i = 1; i <= n; i++){
        //A~I로 인지하였을 경우
        if (password[i] >= 1 && password[i] <= 9)
                cache[i] = (cache[i - 1] + cache[i]) % MOD;
        if (i == 1)
                continue;
        //J~Z로 인지하였을 경우
        int temp = password[i] + password[i - 1] * 10;
        if (10 <= temp && temp <= 26)
                cache[i] = (cache[i - 2] + cache[i]) % MOD;
    }
    return cache[n];
}

int main(void){
    string secret;
    cin >> secret;
    n = secret.length();
    for(int i = 0; i < n; ++i){
        password[i+1] = secret[i] - '0';
    }
    if(secret[0]=='0')
        cout << 0 << endl;
    else{
        cout << numOfDecoding() << endl;
    }
    return 0;
}