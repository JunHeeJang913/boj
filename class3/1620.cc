#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int n, m;
map<string, int> ency;
vector<string> ency2;

void solve()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string input; cin >> input;
    int input_n=0;
    if(!isalpha(input[0]))
    {
        for(int i = 0; i < input.length(); ++i)
        {
            input_n += (input[i] - '0');
            input_n *= 10;
        }
        input_n /= 10;

        cout << ency2[input_n] << '\n';
    } 
    else
    {
        cout << ency[input] << '\n';
    }

    return;
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    ency2 = vector<string>(n+1);
    for(int i = 1; i <= n; ++i)
    {
        string temp; cin >> temp;
        ency[temp] = i;
        ency2[i] = temp;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    for(int i = 0; i < m; ++i)
        solve();
    return 0;
}