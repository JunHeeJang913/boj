#include <vector>
#include <iostream>

using namespace std;
const int MAX = 10001;
int diameter;
int endPoint;
int n;
vector<pair<int, int> > tree[MAX];
vector<bool> visited;

void init(){
    cin >> n;
    for(int i = 0; i < n - 1; ++i){
        int parent;
        cin >> parent;
        int child, weight;
        cin >> child >> weight;
        tree[parent].push_back(make_pair(child, weight));
        tree[child].push_back(make_pair(parent, weight));
    }
    visited = vector<bool>(n+1, false);
}

void dfs(int here, int cost){
    if(visited[here] == true) return;
    visited[here] = true;

    if(diameter < cost){
        diameter = cost;
        endPoint = here;
    }

    for(int i = 0; i < tree[here].size(); ++i){
        pair<int, int> & there = tree[here][i];
        dfs(there.first, cost+there.second);
    }
}

int main(void){
    init();
    dfs(1,0);
    diameter = 0;
    visited = vector<bool>(n+1, false);
    dfs(endPoint, 0);
    cout << diameter;
    return 0;
}