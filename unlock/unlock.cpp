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
uset<int> v;
bool overlap(int a, int b)
{
    if (q.front()[a].first - bl[a].first > q.front()[b].first - tr[b].first || q.front()[b].first - bl[b].first > q.front()[a].first - tr[a].first)
    {
        return false;
    }
    else if (q.front()[a].second - bl[a].second > q.front()[b].second - tr[b].second || q.front()[b].second - bl[b].second > q.front()[a].second - tr[a].second)
    {
        return false;
    }
    return true;
}
bool check_valid(int obj)
{
    int xm = q.front()[obj].first - o[obj].first;
    int ym = q.front()[obj].second - o[obj].second;
    for (int j = 0; j < 3; j++)
    {
        if (j == obj)
        {
            continue;
        }
        if (!overlap(j, obj))
        {
            continue;
        }
        for (int i = 0; i < p[obj]; i++)
        {
            int kx = b[obj][i].first + xm;
            int ky = b[obj][i].second + ym;
            if (s[j][q.front()[j].first - kx][q.front()[j].second - ky])
            {
                return false;
            }
        }
    }
    return true;
}
bool check_ans()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (overlap(i, j))
            {
                return false;
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
    int h = 1;
    h += o[0].first - o[1].first + 10;
    h *= 20;
    h += o[0].second - o[1].second + 10;
    h *= 20;
    h += o[0].first - o[2].first + 10;
    h *= 20;
    h += o[0].second - o[2].second + 10;
    h *= 20;
    h += o[1].first - o[2].first + 10;
    h *= 20;
    h += o[1].second - o[2].second + 10;
    v.insert(h);
    int ans = -1;
    while (!q.empty())
    {
        if (check_ans())
        {
            ans = l.front();
            break;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                q.front()[i].first += dx[j];
                q.front()[i].second += dy[j];
                if (q.front()[i].first >= -9 && q.front()[i].first <= 18 && q.front()[i].second >= -9 && q.front()[i].second <= 18)
                {
                    int h = 1;
                    h += q.front()[0].first - q.front()[1].first + 10;
                    h *= 20;
                    h += q.front()[0].second - q.front()[1].second + 10;
                    h *= 20;
                    h += q.front()[0].first - q.front()[2].first + 10;
                    h *= 20;
                    h += q.front()[0].second - q.front()[2].second + 10;
                    h *= 20;
                    h += q.front()[1].first - q.front()[2].first + 10;
                    h *= 20;
                    h += q.front()[1].second - q.front()[2].second + 10;
                    if (v.find(h) == v.end())
                    {
                        if (check_valid(i))
                        {
                            v.insert(h);
                            q.push(q.front());
                            l.push(l.front() + 1);
                        }
                    }
                }
                q.front()[i].first -= dx[j];
                q.front()[i].second -= dy[j];
            }
        }
        q.pop();
        l.pop();
    }
    cout << ans << endl;
    return 0;
}
