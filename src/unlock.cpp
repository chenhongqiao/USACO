#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
using namespace std;
int p[3];
const int n = 3;
vector<pair<int, int>> b[3];
queue<vector<pair<int, int>>> q;
queue<int> l;
vector<pair<int, int>> o;
pair<int, int> tr[3];
pair<int, int> bl[3];
umap<int, umap<int, bool>> s[3];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
uset<long long> v;
bool overlap(vector<pair<int, int>> st, int a, int b)
{
    if (st[a].first - bl[a].first > st[b].first - tr[b].first || st[b].first - bl[b].first > st[a].first - tr[a].first)
    {
        return false;
    }
    else if (st[a].second - bl[a].second > st[b].second - tr[b].second || st[b].second - bl[b].second > st[a].second - tr[a].second)
    {
        return false;
    }
    return true;
}
bool check_valid(vector<pair<int, int>> st, int obj)
{
    int xm = st[obj].first - o[obj].first;
    int ym = st[obj].second - o[obj].second;
    for (int j = 0; j < 3; j++)
    {
        if (j == obj)
        {
            continue;
        }
        if (!overlap(st, j, obj))
        {
            continue;
        }
        for (int i = 0; i < p[obj]; i++)
        {
            int kx = b[obj][i].first + xm;
            int ky = b[obj][i].second + ym;
            if (s[j][st[j].first - kx][st[j].second - ky])
            {
                return false;
            }
        }
    }
    return true;
}
bool check_ans(vector<pair<int, int>> st)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (overlap(st, i, j))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    auto begin = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < 3; i++)
    {
        tr[i].first = -1000000000;
        tr[i].second = -1000000000;
        bl[i].first = 1000000000;
        bl[i].second = 1000000000;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p[i]; j++)
        {
            int x, y;
            cin >> x >> y;
            b[i].push_back({x, y});
            tr[i].first = max(tr[i].first, x);
            tr[i].second = max(tr[i].second, y);
            bl[i].first = min(bl[i].first, x);
            bl[i].second = min(bl[i].second, y);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        o.push_back({b[i][0].first, b[i][0].second});
    }
    for (int i = 0; i < 3; i++)
    {
        tr[i].first = o[i].first - tr[i].first;
        tr[i].second = o[i].second - tr[i].second;
        bl[i].first = o[i].first - bl[i].first;
        bl[i].second = o[i].second - bl[i].second;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < p[i]; j++)
        {
            s[i][o[i].first - b[i][j].first][o[i].second - b[i][j].second] = true;
        }
    }

    q.push(o);
    l.push(0);
    long long h = 1;
    for (int i = 0; i < 3; i++)
    {
        h *= 40;
        h += o[i].first + 10;
        h *= 40;
        h += o[i].second + 10;
    }
    v.insert(h);
    int ans = -1;
    while (!q.empty())
    {
        vector<pair<int, int>> cur = q.front();
        if (check_ans(cur))
        {
            ans = l.front();
            break;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cur[i].first += dx[j];
                cur[i].second += dy[j];
                if (cur[i].first >= -9 && cur[i].first <= 18 && cur[i].second >= -9 && cur[i].second <= 18)
                {
                    long long h = 1;
                    for (int i = 0; i < 3; i++)
                    {

                        h *= 40;
                        h += cur[i].first + 10;
                        h *= 40;
                        h += cur[i].second + 10;
                    }
                    if (v.find(h) == v.end())
                    {
                        if (check_valid(cur, i))
                        {
                            v.insert(h);
                            q.push(cur);
                            l.push(l.front() + 1);
                        }
                    }
                }
                cur[i].first -= dx[j];
                cur[i].second -= dy[j];
            }
        }
        q.pop();
        l.pop();
    }
    cout << ans << endl;
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(chrono::high_resolution_clock::now() - begin).count();
    cout << "time used=" << dur << " ms" << endl;
    return 0;
}
