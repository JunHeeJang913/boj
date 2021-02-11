#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 100001;

int V;
vector<bool> visited;
vector<pair<int, int> > tree[MAX];
int diameter = 0;
int endPoint;

void init(){
    cin >> V;
    visited = vector<bool>(V+1);

    for(int i = 1; i < V + 1; ++i){
        int node;
        cin >> node;
        while(true){
            int adj; cin >> adj;
            if(adj == -1) break;
            int length; cin >> length;

            tree[node].push_back(make_pair(adj, length));   //중복해서 입력되므로 굳이 노드 위치 바꿀 필요 없을 듯.
        }
    }
}
/*
int getDiameter(){
    sort(length.begin(), length.end(), greater<int>());
    return length[0] + length[1];
}
/*
void dfs(int here, int & len){
    visited[here] = true;
    for(int i = 0; i < tree[here].size(); ++i){
        int there = tree[here][i].first;
        int thereLen = tree[here][i].second;
        if(visited[there] == false){
            len += thereLen;
            dfs(there, len);
        }
    }
}*/
/*
void bfs(int start, int & len){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(q.empty() == false){
        int here = q.front(); q.pop();
        int thereLen = 0;
        for(int i = 0; i < tree[here].size(); ++i){
            int there = tree[here][i].first;
            if(visited[there] == false){
                q.push(there);
                visited[there] = true;
                thereLen = max(thereLen, tree[here][i].second );
            }
        }
        len += thereLen;  
    }
}

//자식이 둘 이상인 아무 노드를 하나 루트로 잡아서 bfs?dfs?
//길이 정보 배열에 저장 후 제일 긴 두개 합 == > 지름
void solve(){
    if(V==2){
        cout << tree[0][0].second;
        return;
    }
    int i;
    for(i = 1; i < V + 1; ++i)
        if(tree[i].size()  > 1) break;
    length = vector<int>(tree[i].size(), 0);
    visited[i] = true;
    for(int j = 0; j < tree[i].size(); ++j){
        bfs(tree[i][j].first, length[j]);
        length[j] += tree[i][j].second;
    }    
    int diameter = getDiameter();
    cout<< diameter;
}*/

void dfs(int here, int cost){
    if(visited[here] == true) return;

    visited[here] = true;

    if(diameter < cost){
        diameter = cost;
        endPoint = here;
    }

    for(int i = 0; i < tree[here].size(); ++i){
        pair<int,int> & there = tree[here][i];
        dfs(there.first, cost + there.second);
    }
}   

int main(void){
    init();
    if(V == 2){
        cout << tree[1][0].second;
        return 0;
    }    
    dfs(1,0);
    visited = vector<bool>(V+1, false);
    diameter = 0;
    dfs(endPoint, 0);


    cout << diameter;
    return 0;
}