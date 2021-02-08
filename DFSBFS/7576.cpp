#include <iostream>
#include <queue>

using namespace std;

//가로 세로
int M, N;
const int MAX = 1000;
int Box[MAX][MAX];
int date = 0;

queue<pair<int, int> > tomato;

//상하좌우
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void initBox(){
    cin >> M >> N;
    for(int y = 0; y < N; ++y){
        for(int x = 0; x < M; ++x){
            cin >> Box[y][x];
            if(Box[y][x] == 1) tomato.push(make_pair(y,x));
        }
    }
}

bool inRange(int y, int x){
    if(y < 0 || y >= N || x < 0 || x >= M) return false;
    return true;
}

void bfs(){
    while(tomato.empty() == false){
        int hereY = tomato.front().first; int hereX = tomato.front().second;
        tomato.pop();
        
        for(int i = 0; i < 4; ++i){
            int thereY = hereY + dy[i]; int thereX = hereX + dx[i];
            if(inRange(thereY, thereX) == true && Box[thereY][thereX] == 0){
                Box[thereY][thereX] = Box[hereY][hereX] + 1;
                tomato.push(make_pair(thereY, thereX));
            }
        }
    }
}

int retDate(){
    for(int y = 0; y < N; ++y){
        for(int x = 0; x < M; ++x){
            if(Box[y][x] == 0) return -1;
            if(date < Box[y][x]) date = Box[y][x];
        }
    }
    return date - 1;
}

int main(void){
    
    initBox();
    bfs();
    cout<<retDate();

    return 0;
}