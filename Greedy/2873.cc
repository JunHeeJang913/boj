#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 1000;
const int INF = 987654321;
int R,C;
int arr[MAX][MAX];
string ans;

int main(void){
    cin >> R >> C;

    if(R % 2 == 1){
        for(int y = 0; y < R; ++y){
            for(int x = 0; x < C - 1; ++x){
                if(y % 2 == 0) ans +='R';
                else ans += 'L';
            }
            if(y != R -1) ans +='D';
        }
    } else if (C % 2 == 1){
        for(int x = 0; x < C; ++x){
            for(int y = 0; y < R - 1; ++y){
                if(x % 2 == 0) ans += 'D';
                else ans += 'U';
            }
            if(x != C-1) ans += 'R';
        }
    } else {
        pair<int, int> minHappy;
        int minScore = INF;
        for(int y = 0; y < R; ++y){
            for(int x = 0; x < C; ++x){
                cin >> arr[y][x];
                if((y+x) % 2 == 1 && minScore > arr[y][x]){
                    minScore = arr[y][x];
                    minHappy = {y,x};
                }
            }
        }
        int newR = minHappy.first % 2 ? minHappy.first - 1 : minHappy.first;
        for(int y = 0; y < newR; ++y){
            for(int x = 0; x < C - 1; ++x)
                if(y%2 == 0) ans +='R';
                else ans += 'L';
            ans += 'D';
        }
        int newC = minHappy.second;
        for(int x = 0; x < newC; ++x){
            if(x%2 == 0) ans += "DR";
            else ans += "UR";
        }
        for(int x = newC; x < C -1; ++x)
            if(x%2== 0) ans += "RD";
            else ans += "RU";
        if(minHappy.first % 2 == 0) newR = R - minHappy.first + 2;
        else newR = R - minHappy.first + 1;
        for(int y = 0; y < newR; ++y){
            ans += 'D';
            for(int x = 0; x < C -1; ++x){
                if( y % 2 == 0) ans += 'L';
                else ans += 'R';
            }
        }
    }

    cout << ans;
    return 0;
}