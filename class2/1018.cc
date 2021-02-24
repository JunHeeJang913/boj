#include <iostream>
#include <string>

using namespace std;

const int length = 8;

int N, M; // height, width

char w_board[8][8] = {
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'}
};

char b_board[8][8]={
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'}    
};

const int MAX = 50;

int ret = 987654321;

char board[MAX][MAX];

void init(){
    cin >> N >> M;
    for(int i = 0; i < N; ++i){
        string s; cin >> s;
        for(int j = 0; j < s.size(); ++j){
            board[i][j] = s[j];
        }
    }
}

void compare_w(int y , int x){
    int temp = 0;
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            if(board[y+i][x+j] != w_board[i][j]) ++temp;
        }
    }
    ret = min(ret, temp);
}

void compare_b(int y , int x){
    int temp = 0;
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            if(board[y+i][x+j] != b_board[i][j]) ++temp;
        }
    }
    ret = min(ret, temp);
}

void findMin(){
    for(int y = 0; y + 7 < N; ++y){
        for(int x = 0; x + 7 < M; ++x){
            compare_w(y, x);
            compare_b(y, x);
        }
    }
    cout << ret << endl;
}

int main(void){
    init();
    findMin();
    return 0;
}