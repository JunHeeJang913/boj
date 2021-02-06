#include <iostream>
#include <vector>

using namespace std;

int N,M;    //정점, 간선
int numOfConCom = 0;
vector<bool> visited;
vector<int> adj[1001];

void dfs(int here){
    visited[here] = true;
    for(int i = 0; i < adj[here].size(); ++i){
        int there = adj[here][i];
        if(visited[there] != true){
            dfs(there);
        }
    }
    return;
}

void dfsAll(){
    visited = vector<bool>(1001, false);
    
    for(int i = 1; i <= N; ++i){
        if(visited[i] != true){
            dfs(i);
            numOfConCom++;
        }
    }
}

void initGraph(int n, int m){
    int a, b;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int main(void){
    cin >> N >> M;
    initGraph(N, M);
    dfsAll();
    cout << numOfConCom;
}