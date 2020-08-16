#include <bits/stdc++.h>
using namespace std;
int h[80005];
stack<int> s;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.empty() || h[i] < s.top())
        {
            s.push(h[i]);
        }
        else
        {
            while (!s.empty() && s.top() <= h[i])
            {
                s.pop();
                ans += s.size();
            }
            s.push(h[i]);
        }
    }
    while (!s.empty())
    {
        s.pop();
        ans += s.size();
    }
    cout << ans << endl;
    return 0;
}