#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> t;
int pick(int p)
{
    priority_queue<int> q;
    for (int i = 0; i < n; i++)
    {
        q.push(t[i]);
    }
    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        int tmp = q.top();
        int num = min(tmp, p);
        if (i >= (k + 1) / 2)
        {
            cnt += num;
        }
        q.pop();
        q.push(tmp - p);
    }
    return cnt;
}
int main()
{
    //freopen("berries.in", "r", stdin);
    //freopen("berries.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        t.push_back(b);
    }

    int ans = 0;
    for (int i = 1; i <= 1000; i++)
    {
        int tmp = pick(i);
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}