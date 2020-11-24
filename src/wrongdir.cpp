#include <bits/stdc++.h>
#define umap unordered_map
using namespace std;
string s;
vector<pair<int, int>> psum;
vector<pair<int, int>> c;
pair<int, int> d = {1, 0};
umap<int, umap<int, bool>> v;
int main()
{
    cin >> s;
    psum.push_back({0, 0});
    c.push_back(d);
    for (int i = 1; i <= s.size(); i++)
    {
        psum.push_back({psum[i - 1].first, psum[i - 1].second});
        if (s[i - 1] == 'F')
        {
            psum[i].first += d.first;
            psum[i].second += d.second;
        }
        else if (s[i - 1] == 'R')
        {
            int tmp = d.first;
            d.first = -d.second;
            d.second = tmp;
        }
        else if (s[i - 1] == 'L')
        {
            int tmp = d.second;
            d.second = -d.first;
            d.first = tmp;
        }
        c.push_back(d);
    }
    long long ans = 0;
    for (int i = 1; i <= s.size(); i++)
    {
        if (s[i - 1] == 'F')
        {
            int dx = psum[s.size()].first - psum[i].first;
            int dy = psum[s.size()].second - psum[i].second;
            if (!v[psum[i].first - dy - c[i - 1].first][psum[i].second + dx - c[i - 1].second])
            {
                ans++;
                v[psum[i].first - dy - c[i - 1].first][psum[i].second + dx - c[i - 1].second] = true;
            }
            if (!v[psum[i].first + dy - c[i - 1].first][psum[i].second - dx - c[i - 1].second])
            {
                ans++;
                v[psum[i].first + dy - c[i - 1].first][psum[i].second - dx - c[i - 1].second] = true;
            }
        }
        if (s[i - 1] == 'R')
        {
            int dx = psum[s.size()].first - psum[i].first;
            int dy = psum[s.size()].second - psum[i].second;
            if (!v[psum[i].first - dx][psum[i].second - dy])
            {
                ans++;
                v[psum[i].first - dx][psum[i].second - dy] = true;
            }
            if (!v[psum[i].first + dy + c[i - 1].first][psum[i].second - dx + c[i - 1].second])
            {
                ans++;
                v[psum[i].first + dy + c[i - 1].first][psum[i].second - dx + c[i - 1].second] = true;
            }
        }
        if (s[i - 1] == 'L')
        {
            int dx = psum[s.size()].first - psum[i].first;
            int dy = psum[s.size()].second - psum[i].second;
            if (!v[psum[i].first - dx][psum[i].second - dy])
            {
                ans++;
                v[psum[i].first - dx][psum[i].second - dy] = true;
            }
            if (!v[psum[i].first - dy + c[i - 1].first][psum[i].second + dx + c[i - 1].second])
            {
                ans++;
                v[psum[i].first - dy + c[i - 1].first][psum[i].second + dx + c[i - 1].second] = true;
            }
        }
    }
    cout << ans << endl;
    return 0;
}