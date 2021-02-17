//풀이를 생각을 못했다.
//참고링크:http://joonas-yoon.blogspot.com/2016/03/1783.html

#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    if(n == 1) cout << 1;
    else if(n == 2) cout << min(4, (m+1)/2);
    else if(m < 7) cout << min(4, m);
    else cout << m - 7 + 5;

    return 0;
}