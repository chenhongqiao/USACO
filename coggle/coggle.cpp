#include <iostream>
#include <map>
using namespace std;
char q[10][10];
bool u[10][10];
string dict[30000];
map<string, short int> m;
int dfs(int x, int y, string t)
{

    if (m[t] != 1 && m[t] != 2)
    {
        return 0;
    }
    int tmp = 0;
    if (m[t] == 2)
    {
        m[t] = 1;
        //cout << t << endl;
        tmp++;
    }
    if (x < 0 || y < 0 || x >= 5 || y >= 5)
    {
        return 0;
    }

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (!u[x + i][y + j])
            {
                u[x + i][y + j] = true;
                int tmp1 = dfs(x + i, y + j, t + q[x + i][y + j]);
                u[x + i][y + j] = false;
                tmp += tmp1;
            }
        }
    }
    return tmp;
}
int main()
{
    //freopen("test", "r", stdin);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> q[i][j];
        }
    }
    int n = 0;
    while (cin >> dict[n])
    {
        n++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < dict[i].size(); j++)
        {
            m[dict[i].substr(0, j)] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        m[dict[i]] = 2;
    }

    int ans = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            string s;
            u[i][j] = true;
            int tmp = dfs(i, j, s + q[i][j]);
            ans += tmp;
            u[i][j] = false;
        }
    }
    cout << ans << endl;
    return 0;
}