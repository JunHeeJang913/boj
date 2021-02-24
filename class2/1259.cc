#include <string>
#include <iostream>

using namespace std;

int main(void)
{
    while (true)
    {
        string s;
        cin >> s;
        if(s == "0") break;
        int s_end = s.size() - 1;
        bool pelin = true;
        for (int i = 0; i < s.size() / 2; ++i)
        {
            if (s[i] != s[s_end - i])
            {
                pelin = false;
                break;
            }
        }

        cout << (pelin ? "yes" : "no") << endl;
    }

    return 0;
}