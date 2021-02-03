/*
정렬된 두 배열.
1<=N,M<=1000000
절대값이 10^9보다 작음.
int : 2,147,483,648
*/

#include <iostream>
#include <vector>

using namespace std;

int n, m;

void printVector(const vector<int> & v){
    for(auto elem : v){
        cout << elem << " ";
    }
}

void merge(vector<int>& a, vector<int>& b,vector<int>& s){
    int idx_a = 0, idx_b = 0;
    s.reserve(n+m);

    while((idx_a < n) && (idx_b < m)){
        if(a[idx_a] > b[idx_b]){
            s.push_back(b[idx_b]);
            ++idx_b;
        } else {
            s.push_back(a[idx_a]);
            ++idx_a;
        }
    }

    if(idx_a < n){
        while(idx_a < n){
            s.push_back(a[idx_a]);
            ++idx_a;
        }
    } else {
        while(idx_b < m){
            s.push_back(b[idx_b]);
            ++idx_b;
        }
    }
}

void input(vector<int>& a, vector<int>& b){
    
    cin >> n >> m;

    a.resize(n);
    b.resize(m);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < m; ++i)
        cin >> b[i];
}

int main(void){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    
    vector<int> A;
    vector<int> B;
    input(A,B);

    vector<int> solved;
    merge(A,B, solved);

    printVector(solved);

    return 0;
}
/*
실행시간 문제가 있었다.
cin, cout 문제
https://eine.tistory.com/entry/CC-%EC%9E%85%EC%B6%9C%EB%A0%A5-%EB%B0%A9%EB%B2%95%EC%97%90-%EB%94%B0%EB%A5%B8-%EC%86%8D%EB%8F%84-%EC%A0%95%EB%A6%AC
참고.
*/