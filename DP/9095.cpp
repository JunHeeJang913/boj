#include <iostream>

using namespace std;

int cache[11];

int numOfWay(int n){
    //wrong base case
    //if(n <= 1) return 1;
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;


    //memoization
    int & ret = cache[n];
    if(ret!=-1) return ret;
    return ret = numOfWay(n-1)+numOfWay(n-2)+numOfWay(n-3);
}

int main(void){
    int T,n;
    cin>>T;
    
    fill_n(cache, 11, -1);

    //Test case : T!!! not n...
    for(int i=0;i<T;++i){
        cin>>n;
        
        int result = numOfWay(n);
        cout<<result<<endl;
    }
    return 0;
}