#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> price;
int N;
int cache[1001];

void input(void){
    cin >> N;
    price.reserve(N+1);
    for(int i = 1; i <= N; ++i)
        cin >> price[i]; 
}

//n장의 카드를 살 때, 지불할 수 있는 최대 금액
int maxPrice(int n){
    //base case
    if(n == 1) return price[1];
    //memoization
    int & ret = cache[n];
    if(ret != -1) return ret;
    ret = price[n];
    for(int i = 1; i < n; ++i){
        ret = max(ret, price[i] + maxPrice(n-i));
    }
    return ret;
}

int main(void){
    input();
    memset(cache, -1, sizeof(cache));
    cout << maxPrice(N) << endl;    
    return 0;
}