#include <iostream>
#include <vector>

using namespace std;
int SIZE;
int c[3] = {0};
vector<vector<int> > matrix;

bool check(const int y, const int x, const int size){
    int val = matrix[y][x];
    for(int i = y; i < y + size; ++i){
        for(int j = x; j < x + size; ++j){
            if(val != matrix[i][j]) return false;
        }
    }
    return true;
}

void solve(const int y, const int x, const int size){
    int & val = matrix[y][x];
    //base case
    if(size == 1){
        ++c[val];
        return;
    }
    if(check(y,x,size)==true){
        ++c[val];
        return; 
    }
    //devide
    int newSize = size/3;
    //TODO:주의하세요!
    for(int newY = y; newY < y + size; newY = newY + newSize){
        for(int newX = x; newX < x + size; newX = newX + newSize){
            solve(newY, newX, newSize);
        }
    }
}

void printRet(){
    for(int i = 0; i < 3; ++i){
        cout << c[i] << '\n';
    }
}

int main(void){
    cin >> SIZE;

    for(int i = 0; i < SIZE; ++i){
        vector<int> row;
        for(int j = 0; j < SIZE; ++j){
            int n;
            cin >> n;
            row.push_back(++n);
        }
        matrix.push_back(row);
    }

    solve(0, 0, SIZE);

    printRet();

    return 0;
}