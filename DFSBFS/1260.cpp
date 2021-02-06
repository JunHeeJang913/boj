#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

/*TODO:종만북에서 발췌
vector<vector<int> > adj;
vector<bool> visited;
//DFS
void dfs(const int here){
    cout << here << ' ';
    visited[here] = true;
    for(int i = 0; i < adj[here].size(); ++i){
        int there = adj[here][i];
        if(visited[there] != true)
            dfs(there);
    }
    return;
}

void dfsAll(){
    visited = vector<bool>(adj.size(), false);
    for(int i = 0; i < adj.size(); ++i){
        if(!visited[i]){
            dfs(i);
        }
    }
}

vector<int> bfs(int start){
    visited = vector<bool>(adj.size(), false);
    queue<int> q;

    vector<int> order;
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int here = q.front();
        q.pop();
        order.push_back(here);
        for(int i = 0; i < adj[here].size(); ++i){
            int there = adj[here][i];
            if(!visited[there]){
                q.push(there);
                visited[there] = true;
            }
        }
    }
    return order;
}*/
const int MAX = 1001;

int N,M,V;
bool adj[MAX][MAX] = {0, };
bool visited[MAX] = {0, };

void dfs(int here){
    cout << here << ' ';
    visited[here] = true;
    for(int there = 0; there <= N; ++there){
        if(adj[here][there] != false && visited[there] == false){
            visited[there] = true;
            dfs(there);
        }
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int here = q.front(); q.pop();
        cout << here << ' ';
        for(int there = 0; there <= N; ++there){
            if(adj[here][there] != false && visited[there] == false){
                q.push(there);
                visited[there] = true;
            }
        }
    }
}

int main(void){
    cin >> N >> M >> V;

    for(int i = 0; i < M; ++i){
        int from, to;
        cin >> from >> to;
        adj[from][to] = true;
        adj[to][from] = true;
    }
    dfs(V);
    cout << '\n';

    memset(visited, false, sizeof(visited));
    bfs(V);
    
    return 0;
}