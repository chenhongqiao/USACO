// Hankson's Quiz
// #define RAND_TEST

#include <iostream>
#include <unordered_map>
#include <cstdlib>
#define umap unordered_map
#define ll long long
using namespace std;
void divide(int n, umap<int, int> &l)
{
    for (int i = 2; (ll)i * i <= n; i++)
    {
        if (n % i == 0)
        {
            l.insert({i, 0});
            while (n % i == 0)
            {
                n /= i;
                l[i]++;
            }
        }
    }
    if (n > 1)
    {
        l.insert({n, 1});
    }
}
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
ll brute(int a0, int a1, int b0, int b1)
{
    ll ans = 0;
    for (int i = 1; i <= b1; i++)
    {
        if (gcd(i, a0) == a1 && ((ll)i * b0) / gcd(i, b0) == b1)
        {
            ans++;
        }
    }
    return ans;
}
ll solve(int a0, int a1, int b0, int b1)
{
    if (a0 % a1 != 0 || b1 % b0 != 0)
    {
        return 0;
    }
    umap<int, pair<int, int>> rst;
    umap<int, int> b0d;
    umap<int, int> b1d;
    divide(b0, b0d);
    divide(b1, b1d);
    umap<int, int> a0d;
    umap<int, int> a1d;
    divide(a0, a0d);
    divide(a1, a1d);
    for (auto it = b1d.begin(); it != b1d.end(); it++)
    {
        int x = it->first;
        int y = it->second;
        if (y > b0d[x])
        {
            rst.insert({x, make_pair(y, y)});
        }
        else
        {
            rst.insert({x, make_pair(0, y)});
        }
    }
    for (auto it = a1d.begin(); it != a1d.end(); it++)
    {
        int x = it->first;
        int y = it->second;
        if (rst.find(x) == rst.end() || (rst[x].first == rst[x].second && rst[x].second != y))
        {
            if (a0d[x] == y && rst[x].second > y)
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
        rst[x].first = y;
        if (a0d[x] > y)
        {
            rst[x].second = min(rst[x].second, y);
        }
        if (rst[x].first > rst[x].second)
        {
            return 0;
        }
    }
    for (auto it = a0d.begin(); it != a0d.end(); it++)
    {
        int x = it->first;
        int y = it->second;
        if (a1d[x] == 0)
        {
            rst[x].second = 0;
        }
        if (rst[x].first > rst[x].second)
        {
            return 0;
        }
    }
    ll ans = 1;
    for (auto it = rst.begin(); it != rst.end(); it++)
    {
        int l = it->second.first;
        int r = it->second.second;
        if (r - l + 1 > 0)
        {
            ans *= (r - l + 1);
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
#ifndef RAND_TEST
        int a0, a1, b0, b1;
        cin >> a0 >> a1 >> b0 >> b1;
        cout << solve(a0, a1, b0, b1) << "\n";
#endif
#ifdef RAND_TEST
        int a1 = rand() % 1000 + 1;
        int a0 = a1 * (rand() % 100 + 1);
        int b0 = rand() % 1000 + 1;
        int b1 = b0 * (rand() % 100 + 1);
        int brt = brute(a0, a1, b0, b1);
        int slv = solve(a0, a1, b0, b1);
        if (brt != slv)
        {
            cout << "bad"
                 << "\n";
        }
#endif
    }
    return 0;
}