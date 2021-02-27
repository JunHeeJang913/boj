#include <iostream>
#include <unordered_map>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n; cin >> n;

    unordered_map<int, int> cards;
    for(int i = 0; i < n; ++i){
        int num; cin >> num;
        ++cards[num];
    }

    int m; cin >> m;
    for(int i = 0; i < m; ++i){
        int num; cin >> num;
        cout << cards[num] << " ";
    }

    return 0;
}