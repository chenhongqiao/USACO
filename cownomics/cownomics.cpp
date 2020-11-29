#include <bits/stdc++.h>
using namespace std;
char ys[505][55];
char ns[505][55];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ys[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ns[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            for (int k = j + 1; k < m; k++)
            {
                map<char, map<char, map<char, int>>> mp;
                for (int l = 0; l < n; l++)
                {
                    mp[ys[l][i]][ys[l][j]][ys[l][k]]++;
                }
                bool is_ans = true;
                for (int l = 0; l < n; l++)
                {
                    if (mp[ns[l][i]][ns[l][j]][ns[l][k]] != 0)
                    {
                        is_ans = false;
                        break;
                    }
                }
                if (is_ans)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}