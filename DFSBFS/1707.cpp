#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 20000 + 1;

int k,v,e;
vector<int> graph[MAX];
int nodeColor[MAX];

void dfs(int here, int color){
    nodeColor[here] = color;
    for(int i = 0; i < graph[here].size(); ++i){
        int there = graph[here][i];
        if(nodeColor[there] == 0){
            dfs(there, 3-color);
        }
    }
}

void dfsAll(){
    int color = 1;
    for(int i = 1; i <= v; ++i){
        if(nodeColor[i] == 0){
            dfs(i, color);
        }
    }
}

bool isBiGraph(){
    for(int i = 1; i <= v; ++i){
        for(int j = 0; j < graph[i].size(); ++j){
            int adjColor = nodeColor[graph[i][j]];
            if(nodeColor[i] == adjColor)
                return false;
        }
    }
    return true;
}

void initSetting(){
    for(int i = 0; i < MAX; ++i){
        graph[i].clear();
    }
    for(int i = 0; i < MAX; ++i){
        nodeColor[i] = 0;
    }
}

void initGraph(){
    int a,b;
    for(int i = 0; i < e; ++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

int main(void){
    cin >> k;
    
    for(int i = 0; i < k; ++i){
        initSetting();
        cin >> v >> e;
        initGraph();
        dfsAll();
        if(isBiGraph() == true)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}