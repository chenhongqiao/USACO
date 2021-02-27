#include <bits/stdc++.h>
using namespace std;
deque<int> c;
int n;
int tree[100005];
vector<int> ans;
void add(int p)
{
    while (p <= n)
    {
        tree[p]++;
        p += p & -p;
    }
}
int sum(int p)
{
    int s = 0;
    while (p > 0)
    {
        s += tree[p];
        p -= p & -p;
    }
    return s;
}
int main()
{
    //freopen("sleepy.in", "r", stdin);
    //freopen("sleepy.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        c.push_back(v);
    }
    int l = 1000000000;
    while (c.back() < l)
    {
        l = c.back();
        add(l);
        c.pop_back();
    }
    cout << c.size() << endl;
    while (!c.empty())
    {
        ans.push_back(n - (sum(n) - sum(c.front())) - 1);
        add(c.front());
        c.pop_front();
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}