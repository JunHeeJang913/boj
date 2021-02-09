#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100;
int n;
int islandNum = 0;

int map[MAX][MAX];
bool visited[MAX][MAX] = {0, };

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

bool inRange(int y, int x){
    if(y < 0 || y >= n || x < 0 || x >= n) return false;
    return true;
}

void dfs(int hereY, int hereX){
    visited[hereY][hereX] = true;
    map[hereY][hereX] = islandNum;
    
    for(int i = 0; i < 4; ++i){
        int thereY = hereY + dy[i];
        int thereX = hereX + dx[i];

        if((inRange(thereY,thereX) == true) && (map[thereY][thereX] == 1) && (visited[thereY][thereX] == false)) 
            dfs(thereY, thereX);
    }
}

void dfsAll(){
    for(int y = 0; y < n; ++y){
        for(int x = 0; x < n; ++x){
            if(map[y][x] != 0 && visited[y][x] == false){
                islandNum += 1;
                dfs(y, x);
            }
        }
    }
}

int bfs(int isNum){
    queue<pair<int, int> > q;
    for(int y = 0; y < n; ++y){
        for(int x = 0; x < n; ++x){
            if(map[y][x] == isNum){
                visited[y][x] == true;
                q.push(make_pair(y,x));
            }
        }
    }
    int result = 0;
    while(!q.empty()){
        int curSize = q.size();
        for(int i = 0; i < curSize; ++i){
            int hereY = q.front().first;
            int hereX = q.front().second;
            q.pop();

            for(int j = 0; j < 4; ++j){
                int thereY = hereY + dy[j];
                int thereX = hereX + dx[j];

                if(inRange(thereY,thereX) == true){
                    if(map[thereY][thereX] != 0 && map[thereY][thereX] != isNum) return result;
                    
                    else if(map[thereY][thereX] == 0 && visited[thereY][thereX] == false){
                        visited[thereY][thereX] = true;
                        q.push(make_pair(thereY, thereX));
                    }
                }
            }
        }
        ++result;
    }
}

void initMap(){
    cin >> n;
    for(int y = 0; y < n; ++y)
        for(int x = 0; x < n; ++x)
            cin >> map[y][x];
}

void resetVis(){
    for(int y = 0; y < n; ++y)
        for(int x = 0; x < n; ++x)
            visited[y][x] = false;
}

int main(void){
    initMap();
    dfsAll();
    int result = 987654321;
    for(int i = 0; i < islandNum; ++i){
        resetVis();
        result = min(result, bfs(i+1));
    }
    cout << result;
    return 0;
}