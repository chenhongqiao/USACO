#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    int num = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            cnt++;
        }
        else if (s[i] == ')')
        {
            num++;
            cnt--;
        }
        if (cnt < 0)
        {
            cout << num << endl;
            return 0;
        }
    }
    cnt = 0;
    num = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ')')
        {
            cnt++;
        }
        else if (s[i] == '(')
        {
            num++;
            cnt--;
        }
        if (cnt < 0)
        {
            cout << num << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}