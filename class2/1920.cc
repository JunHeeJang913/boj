#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool bSearch(const vector<int>& v, int num){
    int start = 0; int end = v.size()-1; int mid = (start + end) / 2;
    bool exist = false;
    while(start <= end){
        if(v[mid] < num){
            start = mid + 1;
        } else if(v[mid] > num){
            end = mid -1;
        } else {
            exist = true;
            break;
        }
        mid = (start + end) / 2;
    }
    return exist;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> seq(n);
    for(int i = 0; i < n; ++i){
        cin >> seq[i];
    }
    int m; cin >> m;
    vector<int> for_seek(m);
    for(int i = 0; i < m; ++i){
        cin >> for_seek[i];
    }

    sort(seq.begin(), seq.end());
    
    //binary search
    for(auto elem : for_seek)
        cout << (bSearch(seq, elem)? 1: 0) <<'\n';

    return 0;
}