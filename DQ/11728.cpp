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
    vector<int>::iterator ita, itb;
    ita = a.begin(); 
    itb = b.begin();
    s.reserve(n+m);

    while(ita != a.end() && itb != b.end()){
        if(*ita > *itb){
            s.push_back(*itb);
            ++itb;
        } else {
            s.push_back(*ita);
            ++ita;
        }
    }

    if(ita != a.end()){
        while(ita != a.end()){
            s.push_back(*ita);
            ++ita;
        }
    } else {
        while(itb != b.end()){
            s.push_back(*itb);
            ++itb;
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
    vector<int> A;
    vector<int> B;
    input(A,B);

    vector<int> solved;
    merge(A,B, solved);

    printVector(solved);

    return 0;
}