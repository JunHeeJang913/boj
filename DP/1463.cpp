#include <iostream>
#define INF 987654321
//더 작은 문제..!
//더 작은 수를 나누는 횟수..!

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
}

int main(void){
    int n;
    std::cin>>n;
    std::cout<<cnt_of_cal(n);
    return 0;
}

//중복된 연산이 발생하면서 시간 초과