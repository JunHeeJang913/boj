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
        
    }

    return 0;
}