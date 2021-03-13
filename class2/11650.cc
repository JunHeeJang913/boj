#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    vector<pair<int, int> > cs(n);
    for(int i = 0; i < n; ++i){
        cin >> cs[i].first >> cs[i].second;
    }

    sort(cs.begin(), cs.end());

    for(auto c : cs){
        cout << c.first << " " << c.second << '\n';
        //FIXME: endl은 생각보다 엄청엄청엄청엄청 느리다...
    }
}