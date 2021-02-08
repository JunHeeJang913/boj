#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 25;
int n;
int numOfDan = 0;
bool biMap[MAX][MAX];
bool visited[MAX][MAX] = {0, };
//상하좌우
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
vector <int> houseNums;
int numOfHouse; 

bool inRange(int y, int x){
    if(y < 0 || y >= n || x < 0 || x >= n) return false;
    return true;
}

void dfs(int hereY, int hereX){
    visited[hereY][hereX] = true;++numOfHouse;
    for(int i = 0; i < 4; ++i){
        int thereY = hereY + dy[i], thereX = hereX + dx[i];
        if(inRange(thereY, thereX) == true){
            if(visited[thereY][thereX] == false && biMap[thereY][thereX] == true){
                dfs(thereY, thereX);
            }
        }
    }
}

void dfsAll(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(visited[i][j] == false && biMap[i][j] == true){
                numOfHouse = 0;
                dfs(i, j);
                ++numOfDan;
                houseNums.push_back(numOfHouse);
            }
        }
    }
}

void setMap(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        string line;
        cin >> line;
        for(int j = 0; j < n; ++j){
            if(line[j] == '0'){
                biMap[i][j] = 0;
            } else {
                biMap[i][j] = 1;
            }
        }
    }
}

int main(void){
    setMap();
    dfsAll();

    cout << numOfDan << endl;
    sort(houseNums.begin(), houseNums.end());
    for(int elem : houseNums){
        cout << elem << '\n';
    }

    return 0;
}