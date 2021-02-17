#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//3의 배수 --> 각자리수 더하여 3의 배수가 나오면 된다.
//제일 큰수가 앞에 오게 하면 된다.

string N;
vector<int> temp;

bool isThreeTimes(){
    int sum = 0; bool isZero = false;
    temp = vector<int>(N.size());
    for(int i = 0; i < N.size(); ++i){
        int num = N[i] - '0';
        sum += num; temp[i] = num;
        if(num == 0) isZero = true;
    }
    if(sum % 3 == 0 && isZero == true) return true; //30의 배수이다. 조심할 것.
    return false;
}

void solve(){
    if(isThreeTimes() == false){
        cout << -1; return;
    }
    sort(temp.begin(), temp.end(), greater<int>()); //벡터 정렬 : 클수록 앞에
    for(int i : temp)
        cout << i;
    return;
}

int main(void){
    cin >> N;
    solve();
    return 0;
}