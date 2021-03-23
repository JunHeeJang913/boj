// N이 주어졌을 때, R행 C열을 몇번째로 방문했는지 출력한다.
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N, r, c;
int cnt = 0;
int l;

inline bool inRange(int y, int x, int leng)
{
    return (r < y + leng && r >= y) && (c < x + leng && c >= x);
}

void Z(int n, int y, int x)
{
    static int ret = 0;
    // base case: n == 1
    if(y == r && x == c)
    {
        cout << ret << '\n';
        return;
    }

    // devide
    if(inRange(y, x, n))
    {
        int next_n = n / 2;
    
        Z(next_n, y, x);
        Z(next_n, y, x + next_n);
        Z(next_n, y+next_n, x);
        Z(next_n, y+next_n, x+next_n);
    }
    else
    {
        ret += n*n;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> r >> c;

    Z(1<<N, 0, 0);

    return 0;
}