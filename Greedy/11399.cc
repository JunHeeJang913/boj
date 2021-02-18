#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> people;
int sum = 0;

void shortest(int end){
    //base case
    if(end == 0) return;

    shortest(end - 1);
    for(int i = 0; i < end; ++i){
        sum += people[i];
    }
}

void input(){
    cin >> N;
    people = vector<int>(N); 
    for(int i = 0; i < N; ++i){
        cin >> people[i];
    }
}

void solve(){
    input();
    sort(people.begin(), people.end());
    shortest(N);
    cout << sum;
}

int main(void){
    solve();
    return 0;
}