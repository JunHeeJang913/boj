#include <iostream>

using namespace std;

const int MAX = 3072;
int N;
char board[MAX][2*MAX];

void initBoard(){
    for(int i = 0; i < MAX; ++i)
        for(int j = 0; j < 2 * MAX; ++j)    //TODO: 배열 범위 항상 잘 생각하기.
            board[i][j] = ' ';
}

void draw(int y, int x, int n){
    //base case 
    if(n == 3){
        board[y-2][x+2] = '*';
        board[y-1][x+1] = '*';  board[y-1][x+3] = '*';
        board[y][x] = '*'; board[y][x+1] = '*';board[y][x+2] = '*';board[y][x+3] = '*';board[y][x+4] = '*';
        return;
    }
    //recursion
    draw(y - (n/2), x + (n/2), n/2);
    draw(y, x, n / 2);
    draw(y, x + n, n/2);
    
    return;
}

void printArr(){
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < 2*N; ++j)
            cout << board[i][j];
        cout << '\n';
    }
        
}

int main(void){

    cin >> N;

    initBoard();

    draw(N-1, 0, N);
    printArr();

    return 0;
}