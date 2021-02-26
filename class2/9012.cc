#include <iostream>
#include <string>

using namespace std;

bool isVPS(const string & cand){
    if(cand[0] != '(') return false;
    if(cand[cand.size()-1] != ')') return false;
    int left_side = 0, right_side = 0;
    for(char ch : cand){
        if(ch == '(') ++left_side;
        else ++right_side;
        if(left_side - right_side < 0) return false;
    }
    if(left_side != right_side) return false;
    return true;
}

int main(void){

    int T; cin >> T;

    for(int i = 0; i < T; ++i){
        string candidate; cin >> candidate;
        if(isVPS(candidate)) cout << "YES";
        else cout << "NO";
        cout << endl;
    }

    return 0;
}