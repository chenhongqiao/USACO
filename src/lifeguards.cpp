#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> s;
bool comp(const pair<int, int> a, const pair<int, int> b)
{
    return a.first < b.first;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int b, e;
        cin >> b >> e;
        s.push_back({b, e});
    }
    sort(s.begin(), s.end(), comp);
    int cvt = 0;
    int lst = 0;
    int lt = 1000000005;
    for (int i = 0; i < n; i++)
    {
        if (s[i].second < lst)
        {
            lt = 0;
            continue;
        }
        cvt += (s[i].second - s[i].first);
        int tmp = s[i].second - s[i].first;
        if (lst > s[i].first)
        {
            cvt -= lst - s[i].first;
            tmp -= lst - s[i].first;
        }
        if (i != n - 1 && s[i].second > s[i + 1].first)
        {
            tmp -= s[i].second - s[i + 1].first;
        }
        lst = s[i].second;
        lt = min(lt, tmp);
    }
    cout << cvt - lt << endl;
    return 0;
}