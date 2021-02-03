#include <iostream>
#include <vector>
#include <string>

using namespace std;

int SIZE;
vector<vector<int> > video;

bool check(int y, int x, int size){
    int & val = video[y][x];

    for(int i = y; i < y + size; ++i){
        for(int j = x; j < x + size; ++j){
            if(val != video[i][j]) return false;
        }
    }
    return true;
}

void solve(int y, int x, int size){
    int & val = video[y][x];
    //base case
    if(size == 1){
        cout << val;
        return;
    }
    
    if(check(y,x,size) == true){
        cout << val;
        return;
    }
    cout << '(';
    int newSize = size / 2;
    for(int newY = y; newY < y + size; newY = newY + newSize){
        for(int newX = x; newX < x + size; newX = newX + newSize){
            solve(newY,newX,newSize);
        }
    }
    cout << ')';
}

int main(void){
    cin >> SIZE;

    for(int i = 0; i < SIZE; ++i){
        vector<int> row;
        string s;
        cin >> s;
        for(int j = 0; j < SIZE; ++j){
            row.push_back(s[j] - '0');
        }
        video.push_back(row);
    }

    solve(0, 0, SIZE);

    return 0;
}