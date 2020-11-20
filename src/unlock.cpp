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
umap<int, umap<int, bool>> s[3];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
uset<string> v;
queue<string> rec;
bool check_valid(vector<pair<int, int>> st, int obj)
{
    int xm = st[obj].first - o[obj].first;
    int ym = st[obj].second - o[obj].second;
    for (int i = 0; i < p[obj]; i++)
    {
        int kx = b[obj][i].first + xm;
        int ky = b[obj][i].second + ym;
        for (int j = 0; j < 3; j++)
        {
            if (j == obj)
            {
                continue;
            }
            if (s[j][st[j].first - kx][st[j].second - ky])
            {
                return false;
            }
        }
    }
    return true;
}
bool check_ans(vector<pair<int, int>> st, int obj)
{
    int xm = st[obj].first - o[obj].first;
    int ym = st[obj].second - o[obj].second;
    for (int i = 0; i < p[obj]; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == obj)
            {
                continue;
            }
            for (int k = 0; k < 4; k++)
            {
                int kx = b[obj][i].first + xm + dx[k];
                int ky = b[obj][i].second + ym + dy[k];
                if (s[j][st[j].first - kx][st[j].second - ky])
                {
                    return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p[i]; j++)
        {
            int x, y;
            cin >> x >> y;
            b[i].push_back({x, y});
        }
    }
    for (int i = 0; i < 3; i++)
    {
        o.push_back({b[i][0].first, b[i][0].second});
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
    string h;
    for (int i = 0; i < 3; i++)
    {
        h += "(";
        h += to_string(o[i].first);
        h += ",";
        h += to_string(o[i].second);
        h += ") ";
    }
    v.insert(h);
    rec.push(h);
    int ans = -1;
    while (!q.empty())
    {
        vector<pair<int, int>> cur = q.front();

        int cnt = 0;
        for (int i = 0; i < 3; i++)
        {
            if (check_ans(cur, i))
            {
                cnt++;
            }
        }
        if (cnt == 3)
        {
            ans = l.front();
            cout << rec.front() << endl;
            break;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cur[i].first += dx[j];
                cur[i].second += dy[j];
                string h;
                for (int i = 0; i < 3; i++)
                {
                    h += "(";
                    h += to_string(cur[i].first);
                    h += ",";
                    h += to_string(cur[i].second);
                    h += ") ";
                }
                if (v.find(h) == v.end())
                {
                    if (check_valid(cur, i))
                    {
                        rec.push(h);
                        v.insert(h);
                        q.push(cur);
                        l.push(l.front() + 1);
                    }
                }
                cur[i].first -= dx[j];
                cur[i].second -= dy[j];
            }
        }
        q.pop();
        l.pop();
        rec.pop();
    }
    cout << ans << endl;
    return 0;
}
