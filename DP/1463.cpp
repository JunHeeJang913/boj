#include <iostream>
#define INF 987654321

using namespace std;
//더 작은 문제..!
//더 작은 수를 나누는 횟수..!
/*
int min(int a, int b, int c){
    if(a<0) a=INF;
    if(b<0) b=INF;
    if(c<0) c=INF;
    if(a<b&&a<c) return a;
    else if(b<a&&b<c) return b;
    else return c;
}

int cnt_of_cal(int n){
    if(n==1) return 0;
    else if(n==2||n==3) return 1;
    int cnt1=-1,cnt2=-1,cnt3=-1;
    if(n%3==0)
        cnt1 = cnt_of_cal(n/3)+1;
    if(n%2==0)
        cnt2 = cnt_of_cal(n/2)+1;
    cnt3 = cnt_of_cal(n-1)+1;

    int cnt=min(cnt1,cnt2,cnt3);

    return cnt;
}*/

int cache[1000001]={0,};

int cnt_of_cal(int n){
    /*
    for(int i = 2; i<=n;i++){
        cache[i] = cache[i-1]+1;
        if(i%2 == 0)
            cache[i] = min(cache[i] , cache[i/2]+1);
        if(i%3==0)
            cache[i] = min(cache[i], cache[i/3]+1);
    }*/
    if(cache[n]) return cache[n];
    switch(n){
    case 1:
        cache[n] = 0;
        break;
    case 2:
    case 3:
        cache[n]=1;
        break;
    default:
        if(n%3==0)
            cache[n] = cnt_of_cal(n/3)+1;
        if(n%2==0)
            cache[n] = cache[n]>(cnt_of_cal(n/2)+1)?(cnt_of_cal(n/2)+1):cache[n];
        cache[n] = cache[n]>(cnt_of_cal(n-1)+1)?(cnt_of_cal(n-1)+1):cache[n];
        break;
    }

    return cache[n];
}

int main(void){
    int n;
    cin>>n;
    cache[1]=0;
    cout<<cnt_of_cal(n);
    return 0;
}