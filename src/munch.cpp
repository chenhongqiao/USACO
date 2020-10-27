#include <bits/stdc++.h>
using namespace std;
char m[105][105];
bool v[105][105];
int dirx[4] = {0, 0, 1, -1};
int diry[4] = {1, -1, 0, 0};
struct point
{
    int x, y;
    int s;
};
int main()
{
    int r, c;
    cin >> r >> c;
    int sx, sy;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> m[i][j];
            if (m[i][j] == 'C')
            {
                sx = i;
                sy = j;
            }
        }
    }
    queue<point> q;
    point st;
    st.x = sx;
    st.y = sy;
    st.s = 1;
    q.push(st);
    v[r][c] = true;
    int ans = 100000000;
    while (!q.empty())
    {
        int cx = q.front().x;
        int cy = q.front().y;
        for (int i = 0; i < 4; i++)
        {
            if (m[cx + dirx[i]][cy + diry[i]] == '.' && !v[cx + dirx[i]][cy + diry[i]])
            {
                v[cx + dirx[i]][cy + diry[i]] = true;
                point tmp;
                tmp.x = cx + dirx[i];
                tmp.y = cy + diry[i];
                tmp.s = q.front().s + 1;
                q.push(tmp);
            }
            if (m[cx + dirx[i]][cy + diry[i]] == 'B')
            {
                ans = min(ans, q.front().s);
            }
        }
        q.pop();
    }
    cout << ans << endl;
    return 0;
}