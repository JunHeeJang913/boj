#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> time;
int n;
vector<time> conferences;

//compare 함수 작성 참고링크
//https://blockdmask.tistory.com/178
bool compare(time time1, time time2){
    if(time1.second == time2.second){
        return time1.first < time2.first; //종료 시간이 같다면, 시작시간이 빠른 순으로 정렬한다.
    } else {
        return time1.second < time2.second; //종료시간 기준!
    }
}

void solve(){
    sort(conferences.begin(), conferences.end(), compare);
    int num_of_conf = 0; int last_end = 0;

    for(int i = 0; i < conferences.size(); ++i){
        if(last_end <= conferences[i].first){
            last_end = conferences[i].second;
            ++num_of_conf;
        }
    }

    cout << num_of_conf;
}

void input(){
    cin >> n;
    conferences = vector<time>(n);
    for(int i = 0; i < n; ++i){
        int begin, end;
        cin >> begin >> end;
        conferences[i] = make_pair(begin, end);
    }
}

int main(void){
    input();
    solve();
    return 0;
}