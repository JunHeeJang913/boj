#include <iostream>
#include <vector>

using namespace std;

int k;
vector<int> value;
int num_of_coin = 0;

//배수조건!

int cal(){
    int i = 0;
    while(k != 0){
        num_of_coin += (k / value[i]);
        k %= value[i++];
    }
    return num_of_coin;
}

void input(){
    int n;
    cin>>n>>k;
    value = vector<int>(n);
    for(int i = 0; i < n; ++i){
        cin >> value[n-1 - i];
    }
}

int main(){
    input();
    cout << cal();
    return 0;
}