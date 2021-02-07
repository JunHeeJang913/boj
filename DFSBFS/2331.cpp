#include <iostream>
#include <vector>

using namespace std;

int A;
int P;
const int MAX = 295245 + 1;
int visited[MAX] = {0, };

int power(int under, int win){
    int pow = 1;
    for(int i = 0; i < win; ++i){
        pow = pow*under;
    }
    return pow;
}

int getNextNum(int a){
    int next = 0;
    while(a > 0){
        next += power(a%10, P);
        a = a / 10;
    }
    return next;
}

void search(int cur){
    ++visited[cur];
    if(visited[cur] > 2) return;
    //TODO:왜 2보다 커야하는가?
    //만약 1보다 큰 경우로 하면 한번 등장한 모든 수가 세어진다.
    int next = getNextNum(cur);
    search(next);
}

int numOfUniter(){
    int count =0;
    for(int i = 0; i < MAX; ++i){
        if(visited[i] == 1) ++count;
    }
    return count;
}

void solve(){
    search(A);
    cout << numOfUniter();
}

int main(void){
    cin >> A >> P;
    solve();
}