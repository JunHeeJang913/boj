#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
//FIXME:문제 잘못 이해함. 연속 세잔 안되고, 몇잔이든 마실 수 있음. 
/*
int findMinIndex(int * group){
    int index;
    if(group[0] <= group[1] && group[0] <= group[2])
        index = 0;
    else if(group[1] <= group[0] && group[1] <= group[2])
        index = 1;
    else
        index = 2;   

    return index; 
}

int findMaxAmount(const vector<int> & wine){
    int group[3] = {wine[0], wine[1], wine[2]}; 
    int groupMin; int groupMinIndex;

    groupMinIndex = findMinIndex(group);
    groupMin = group[groupMinIndex];

    for(int i = 3; i < wine.size(); ++i){
        if(groupMin < wine[i]){
            group[groupMinIndex] = wine[i];
            groupMinIndex = findMinIndex(group);
            groupMin = group[groupMinIndex];
        }
    }
    
    int maxAmount = 0;
    for(int i = 0; i < 3; ++i){
        maxAmount += group[i];
    }

    return maxAmount;
}*/

int cache[10001];
int wine[10001];

int findMaxAmount(int n){
    //base case:
    if(n == 0) return 0;
    else if(n == 1) return wine[1];
    else if( n == 2 ) return wine[1]+wine[2];
    //memoization:
    int & ret = cache[n];
    if(ret != -1) return ret;
    ret = max(max(findMaxAmount(n-2),findMaxAmount(n-3)+wine[n-1])+wine[n], findMaxAmount(n-1));
    return ret;
}

int main(void){
    int n;
    cin >> n;
    
    memset(cache, -1, sizeof(cache));
    
    for(int i = 1; i<=n; ++i){
        int amount;
        cin>>amount;
        wine[i] = amount;
    }

    int result = findMaxAmount(n);

    cout<< result << endl;

    return 0;
}