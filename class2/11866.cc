#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, k; cin >> n >> k;
    queue<int> josephus;
    for(int i = 1; i <= n; ++i){
        josephus.push(i);
    }
    cout << '<';
    while(josephus.empty() == false){
        for(int i = 0; i < k; ++i){
            int temp = josephus.front(); josephus.pop();
            if(i != k-1){
                josephus.push(temp);
            } else {
                cout << temp;
            }
        }
        if(josephus.size() != 0) cout << ", ";
    }
    cout << '>';
    return 0;
}