#include <iostream>
#include <vector>
using namespace std;

//brute force로 풀어도 시간이 여유있겠다.
vector<int> scores;
int n_card;
int wanted;

void init(){
    cin >> n_card >> wanted;
    scores = vector<int>(n_card);
    for(int i = 0; i < n_card; ++i)
        cin >> scores[i];
}

int solve(){
    int min_diff = 987654321;
    int max_sum;
    for(int i = 0; i < n_card; ++i)
        for(int j = i+1; j < n_card; ++j)
            for(int k = j + 1; k < n_card; ++k){
                int temp_sum = scores[i] + scores[j] + scores[k];
                int temp_diff = wanted - temp_sum;
                if(0 <= temp_diff && temp_diff < min_diff) {
                    min_diff = temp_diff;
                    max_sum = temp_sum;
                }
            }
    return max_sum;
}

int main(void){
    init();
    cout << solve();
    return 0;
}