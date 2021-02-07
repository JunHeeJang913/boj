//순열 사이클이랑 비슷한 문제

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100001;
int n; int cnt;
vector<int> graph(MAX);
vector<bool> visited(MAX);
vector<bool> done(MAX);

void initSetting(){
    cnt = 0;
    graph.clear();
    visited = vector<bool>(MAX, false);
    done = vector<bool>(MAX, false);
}

void initGraph(){
    cin >> n;
    for(int from = 1; from <= n; ++from){
        int to;
        cin >> to;
        graph[from] = to;
    }
}

void dfs(int here){
    visited[here] = true;
    int there = graph[here];
    if(visited[there] == false){      
        dfs(there);
    } else if(done[there] == false) {
        for(int i = there; i != here; i = graph[i]){
            ++cnt;
        }
        ++cnt;
    }

    done[here] = true;
}

void dfsAll(){
    for(int i = 1; i <= n; ++i){
        if(visited[i] == false)
            dfs(i);
    }
}

int main(void){
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i){
        initSetting();
        initGraph();
        dfsAll();
        cout<< n - cnt << endl;
    }
    return 0;
}