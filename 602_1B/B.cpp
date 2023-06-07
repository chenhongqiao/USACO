// Addition and Subtraction Hard
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, char>> s(n);
    for (int i = 0; i < n; i++)
    {
        auto &[a, o] = s[i];
        cin >> a;
        if (i != n - 1)
        {
            cin >> o;
        }
        else
        {
            o = '*';
        }
    }
    long long rs[n];
    for (int i = n - 1; i >= 0; i--)
    {
        rs[i] = s[i].first;
        if (i != n - 1)
        {
            rs[i] += rs[i + 1];
        }
    }
    long long rc[n];
    for (int i = n - 1; i >= 0; i--)
    {
        auto [a, o] = s[i];
        if (i == n - 1 || o == '-')
        {
            rc[i] = a;
        }
        else
        {
            rc[i] = rc[i + 1] + a;
        }
    }
    long long ans = 0;
    long long cnt = 0;
    int sign = 1;
    for (int i = 0; i < n; i++)
    {
        auto [a, o] = s[i];
        cnt += sign * a;
        if (o == '-')
        {
            ans = max(ans, cnt + rs[i + 1] - rc[i + 1] * 2);
            sign = -1;
        }
        else if (o == '+')
        {
            sign = 1;
        }
    }
    cout << max(ans, cnt) << endl;
    return 0;
}