#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

//1보다 크면 묶어버린다. 음수가 두개 이상이라면..?
//TODO: 0이랑 음수를 엮을 수 있다. 주의하자.
priority_queue<int> biggerThanOne;
priority_queue<int> negative;
bool zero = false;
int one = 0;

void input(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int number;
        cin >> number;
        if(number < 0){
            negative.push(-number);
        } else if(number == 0){
            zero = true;
        } else if(number == 1) {
            one += 1;
        } else {
            biggerThanOne.push(number);
        }
    }
    return;
}

int cal(){
    int ret = 0;
    while(biggerThanOne.size() > 1){
        int first = biggerThanOne.top(); biggerThanOne.pop();
        int second = biggerThanOne.top(); biggerThanOne.pop();
        ret += first * second;
    }
    if(biggerThanOne.size() != 0)
        ret += biggerThanOne.top();

    while(negative.size() > 1){
        int first = -negative.top(); negative.pop();
        int second = -negative.top(); negative.pop();
        ret += first * second;
    }
    if(negative.size() != 0 && zero == false)   //0이 있을 때는 자동으로 넘어감.
        ret += -negative.top();
    if(one)
        ret += one;
    return ret;
}

void solve(){
    input();
    int solution = cal();
    cout << solution;
}

int main(void){
    solve();
    return 0;
}