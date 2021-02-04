#include <iostream>
#include <vector>

using namespace std;

const int MAX = 2187;       // 3^7
int SIZE;
char starArray[MAX][MAX] = {0};

void initBoard(){
    for(int i = 0; i < MAX; ++i){
        for(int j = 0; j < MAX; ++j)
            starArray[i][j] = ' ';
    }
}

void drawStar(int y, int x, int n){
    //base case
    if(n == 1){
        starArray[y][x] = '*';
        return ;
    }
    //recursion
    int newN = n / 3;    
    for(int newY = y; newY < y + n; newY += newN){
        for(int newX = x; newX < x + n; newX += newN){
            if(newX == x + newN && newY == y + newN) continue;
            drawStar(newY, newX, newN);
        }
    }
}

void printStar(){
    
    drawStar(0, 0, SIZE);
    for(int y = 0; y < SIZE; ++y){
        for(int x = 0; x < SIZE; ++x){
            cout << starArray[y][x];
        }
        cout << '\n';
    }
}

int main(void){
    cin >> SIZE;

    initBoard();
    printStar();

    return 0;
}