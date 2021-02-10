#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100001;
int n;  //노드의 개수

vector<int> tree[MAX];
vector<int> parent;
vector<bool> visited;

void printParent(){
    for(int i = 2; i < n + 1; ++i){
        cout << parent[i] << '\n';
    }
}

void findParent(int start){ //by bfs
    queue<int> q;
    q.push(start);
    while(q.empty() == false){
        int here = q.front(); q.pop();
        visited[here] = true;
        for(int i = 0; i < tree[here].size(); ++i){
            int there = tree[here][i];
            if(visited[there] == false){
                parent[there] = here;
                q.push(there);
            }
        }
    }
}

void initTree(){
    cin >> n;
    parent = vector<int>(n+1);
    visited = vector<bool>(n+1, false);
    for(int i = 0; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
}

int main(void){
    initTree();
    findParent(1);
    printParent();
}