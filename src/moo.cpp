#include <bits/stdc++.h>
using namespace std;
vector<pair<bool, int>> s;  //true->is mirror, then tail; false->not mirror, then o number after this;
vector<pair<int, int>> cov; //coverage; including head, not tail.
int n;
bool comp(int a, pair<int, int> b)
{
    return a < b.first;
}
void generate(int pos, int dep)
{
    if (pos > n + 10)
    {
        return;
    }
    int ssz = s.size();
    s.push_back({false, dep + 2});
    cov.push_back({pos, pos + dep + 3});
    if (ssz > 0)
    {
        s.push_back({true, ssz});
        cov.push_back({pos + dep + 3, pos * 2 + dep + 3});
    }
    if (ssz > 0)
    {
        generate(pos * 2 + (dep + 3), dep + 1);
    }
    else
    {
        generate(pos + (dep + 3), dep + 1);
    }
}
void solve(int h, int t, int m)
{
    int p = -100;
    for (int i = h; i < t; i++)
    {
        if (cov[i].first <= m && m < cov[i].second)
        {
            p = i;
            break;
        }
    }

    if (!s[p].first)
    {
        if (cov[p].first == m)
        {
            cout << "m" << endl;
            return;
        }
        else
        {
            cout << "o" << endl;
            return;
        }
    }
    else
    {
        solve(0, s[p].second, m - cov[p].first);
    }
}
void printmoo(int m)
{
    cout << "m";
    for (int i = 0; i < m; i++)
    {
        cout << "o";
    }
}
void print(int h, int t)
{
    for (int i = h; i < t; i++)
    {
        if (!s[i].first)
        {
            printmoo(s[i].second);
        }
        else
        {
            print(0, s[i].second);
        }
    }
}

int main()
{
    cin >> n;
    generate(0, 0);
    //print(0, s.size());
    solve(0, s.size(), n - 1);
    return 0;
}