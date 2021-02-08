#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 50;
int w, h;
int numOfIsland = 0;
bool biMap[MAX][MAX];
bool visited[MAX][MAX];
//상하좌우+대각방향
const int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
const int dy[] = {-1, 1, 0, 0, 1, -1, 1, -1};

void initSetting(){
    for(int y = 0; y < h; ++y){
        for(int x = 0; x < w; ++x){
            biMap[y][x] = 0;
            visited[y][x] = 0;
        }
    }
    numOfIsland = 0;
}

void initMap(){
    bool isLand;
    for(int y = 0; y < h; ++y){
        for(int x = 0; x < w; ++x){
            cin >> isLand;
            biMap[y][x] = isLand;
        }
    }
}

bool inRange(int y, int x){
    if(y < 0 || y >= h || x < 0 || x >= w) return false;
    return true;
}

void dfs(int hereY, int hereX){
    visited[hereY][hereX] = true;
    for(int i = 0; i < 8; ++i){
        int thereY = hereY + dy[i]; 
        int thereX = hereX + dx[i];
        if(inRange(thereY, thereX) == true){
            if(visited[thereY][thereX] == false && biMap[thereY][thereX] == 1)
                dfs(thereY, thereX);
        }
    }
}

void dfsAll(){
    for(int y = 0; y < h; ++y){
        for(int x = 0; x < w; ++x){
            if(visited[y][x] == false && biMap[y][x] == 1){
                dfs(y, x);
                ++numOfIsland;
            }
        }
    }
}

int main(void){
    while(true){
        cin >> w >> h;
        //terminate
        if(w == 0 && h == 0) break;
        initSetting();
        initMap();
        dfsAll();
        cout << numOfIsland << endl;
    }
    return 0;
}