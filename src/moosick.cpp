#include <iostream>
#include <algorithm>
using namespace std;
int s[20010];
int b[20010];
int main()
{
    int n, c;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> b[i];
    }
    sort(b, b + c);
    int ans = 0;
    int ac[20010];
    for (int i = 0; i <= n - c; i++)
    {
        int t[20];
        for (int j = 0; j < c; j++)
        {
            t[j] = s[i + j];
        }
        sort(t, t + c);
        int a = t[0] - b[0];
        bool is_bad = true;
        for (int j = 1; j < c; j++)
        {
            if (t[j] - b[j] != a)
            {
                is_bad = false;
            }
        }
        if (is_bad)
        {
            ac[ans] = i;
            ans++;
        }
    }
    cout << ans << endl;
    for (int i = 0; i < ans; i++)
    {
        cout << ac[i] + 1 << endl;
    }
    return 0;
}