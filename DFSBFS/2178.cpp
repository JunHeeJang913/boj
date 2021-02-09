#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int MAX = 100;

int maze[MAX][MAX] = {0, };
int n, m; // 세로, 가로
queue<pair<int, int> > q;
int endY, endX;
//상하좌우
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void initMaze(){
    cin >> n >> m;
    string line;
    for(int y = 0; y < n; ++y){
        cin >> line;
        for(int x = 0; x < m; ++x){
            if(line[x] == '0') maze[y][x] = 0;
            else if(line[x] == '1') maze[y][x] = 1;
        }
    }
    endY = n-1; endX = m - 1;
}

bool inRange(int y, int x){
    if(y < 0 || y >= n || x < 0 || x >= m) return false;
    return true;
}

void bfs(){
    int startY = 0, startX = 0;
    q.push(make_pair(startY, startX));
    while(q.empty() == false){
        int hereY = q.front().first;
        int hereX = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i){
            int thereY = hereY + dy[i];
            int thereX = hereX + dx[i];
            if(inRange(thereY, thereX) == true && maze[thereY][thereX] == 1){
                maze[thereY][thereX] = maze[hereY][hereX] + 1;
                q.push(make_pair(thereY, thereX));
            }
        }
    }
}

int main(void){
    initMaze();
    bfs();
    cout << maze[endY][endX];
    return 0;
}