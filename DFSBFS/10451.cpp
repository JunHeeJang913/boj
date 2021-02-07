#include <iostream>
#include <vector>

using namespace std;

int N;
int MAX = 1001;
int numOfCycle;
vector<int> graph(MAX);
vector<bool> visited(MAX);

void initSetting(){
    visited = vector<bool>(MAX, false);
    for(int i = 0; i < MAX; ++i){
        graph.clear();
    }
    numOfCycle = 0;
}

void initGraph(){
    for(int from = 1; from <= N; ++from){
        int to; 
        cin >> to;
        graph[from]=to;
    }
}

void dfs(int here){
    visited[here] = true;
    int there = graph[here];
    if(visited[there] == false){
        dfs(there);
    }
}

void dfsAll(){
    for(int i = 1; i <= N; ++i){
        if(visited[i] == false){
            dfs(i);
            ++numOfCycle;
        }
    }
}

int main(void){
    int T;
    cin >> T;

    for(int i = 0; i < T; ++i){
        initSetting();
        cin >> N;
        initGraph();
        dfsAll();
        cout << numOfCycle << endl;
    }

    return 0;
}