#include <bits/stdc++.h>
#define SHIFTN 1000000
using namespace std;
map<int, vector<pair<int, char>>> c;
map<int, vector<pair<int, char>>> r;
vector<pair<int, int>> f;
unordered_set<int> cv;
unordered_set<int> rv;
int n, a, b;
bool comp(const pair<int, char> a, const int b)
{
    return a.first < b;
}
bool check()
{
    int x = SHIFTN;
    int y = SHIFTN;
    int dx = 1;
    int dy = 0;
    while (1)
    {
        if (dx == 0)
        {
            int np = lower_bound(c[x].begin(), c[x].end(), y, comp) - c[x].begin() + dy;
            if (np < 0 || np >= c[x].size())
            {
                return false;
            }
            y = c[x][np].first;
            char nm = c[x][np].second;
            if (nm == '@' && dx == 1 && dy == 0)
            {
                return false;
            }
            else if (nm == '#')
            {
                return true;
            }
            else if (nm == '/')
            {
                int tmp = dx;
                dx = dy;
                dy = tmp;
            }
            else if (nm == '\\')
            {
                int tmp = dx;
                dx = -dy;
                dy = -tmp;
            }
        }
        else if (dy == 0)
        {
            int np = lower_bound(r[y].begin(), r[y].end(), x, comp) - r[y].begin() + dx;
            if (np < 0 || np >= r[y].size())
            {
                return false;
            }
            x = r[y][np].first;
            char nm = r[y][np].second;
            if (nm == '@' && dx == 1 && dy == 0)
            {
                return false;
            }
            else if (nm == '#')
            {
                return true;
            }
            else if (nm == '/')
            {
                int tmp = dx;
                dx = dy;
                dy = tmp;
            }
            else if (nm == '\\')
            {
                int tmp = dx;
                dx = -dy;
                dy = -tmp;
            }
        }
    }
}
int main()
{
    cin >> n >> a >> b;
    a += SHIFTN;
    b += SHIFTN;
    c[SHIFTN].push_back({SHIFTN, '@'});
    r[SHIFTN].push_back({SHIFTN, '@'});
    cv.insert(SHIFTN);
    rv.insert(SHIFTN);
    c[a].push_back({b, '#'});
    r[b].push_back({a, '#'});
    cv.insert(a);
    rv.insert(b);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        char s;
        cin >> x >> y >> s;
        x += SHIFTN;
        y += SHIFTN;
        f.push_back({x, y});
        c[x].push_back({y, s});
        r[y].push_back({x, s});
        cv.insert(x);
        rv.insert(y);
    }
    for (unordered_set<int>::iterator it = cv.begin(); it != cv.end(); it++)
    {
        sort(c[*it].begin(), c[*it].end());
    }
    for (unordered_set<int>::iterator it = rv.begin(); it != rv.end(); it++)
    {
        sort(r[*it].begin(), r[*it].end());
    }
    bool ok = check();
    if (ok)
    {
        cout << 0 << endl;
    }
    else
    {
        for (int i = 0; i < f.size(); i++)
        {
            int x = f[i].first;
            int y = f[i].second;
            int yp = lower_bound(c[x].begin(), c[x].end(), y, comp) - c[x].begin();
            int xp = lower_bound(r[y].begin(), r[y].end(), x, comp) - r[y].begin();
            if (c[x][yp].second == '/')
            {
                c[x][yp].second = '\\';
            }
            else if (c[x][yp].second == '\\')
            {
                c[x][yp].second = '/';
            }
            if (r[y][xp].second == '/')
            {
                r[y][xp].second = '\\';
            }
            else if (r[y][xp].second == '\\')
            {
                r[y][xp].second = '/';
            }
            if (check())
            {
                cout << i + 1 << endl;
                ok = true;
                break;
            }
            if (c[x][yp].second == '/')
            {
                c[x][yp].second = '\\';
            }
            else if (c[x][yp].second == '\\')
            {
                c[x][yp].second = '/';
            }
            if (r[y][xp].second == '/')
            {
                r[y][xp].second = '\\';
            }
            else if (r[y][xp].second == '\\')
            {
                r[y][xp].second = '/';
            }
        }
    }
    if (!ok)
    {
        cout << -1 << endl;
    }
    return 0;
}