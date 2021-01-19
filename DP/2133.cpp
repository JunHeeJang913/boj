#include <iostream>
#include <cstring>

using namespace std;

bool board[3][30];
int cache[31];

void initBoard(int n){
    for(int i = 0; i < n; ++i){
        board[0][i] = true;
        board[1][i] = true;
        board[2][i] = true;
    }
}

int tiling(int width){
    //base case;
    if(width % 2 == 1) return 0;
    if(width == 2) return 3;

    //memoization
    int & ret = cache[width];
    if(ret != -1) return ret;
    
    ret = tiling(width - 2) * tiling(2);
    for(int i = 4; width - i >= 2; i += 2)
        ret += tiling(width-i) * 2;
    ret += 2;

    return ret;
}

int main(void){
    int n;
    cin >> n;
    initBoard(n);

    memset(cache, -1, sizeof(cache));
    cout<<tiling(n);

    return 0;
}