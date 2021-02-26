#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using person = pair<int, string>;

bool compare(person a, person b){
    return a.first < b.first;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin>>n;
    vector<person> member(n);
    for(int i = 0; i < n; ++i){
        int age; string name;
        cin >> age >> name;
        member[i] = make_pair(age, name);
    }
    stable_sort(member.begin(), member.end(), compare);
    for(auto elem: member){
        cout << elem.first << " " << elem.second << '\n';
    }
}
