#include <bits/stdc++.h>
using namespace std;
vector<long long> h;
int main()
{
    //freopen("haybales.in", "r", stdin);
    //freopen("haybales.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        h.push_back(in);
    }
    sort(h.begin(), h.end());
    for (int i = 0; i < q; i++)
    {
        int b, e;
        cin >> b >> e;
        int bp = lower_bound(h.begin(), h.end(), b) - h.begin() - 1;
        int ep = upper_bound(h.begin(), h.end(), e) - h.begin() - 1;
        cout << ep - bp << endl;
    }
    return 0;
}