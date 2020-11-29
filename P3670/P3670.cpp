//A=0,C=1,G=2,T=3
#include <iostream>
using namespace std;
int g[1005][55];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n * 2; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char t;
            cin >> t;
            switch (t)
            {
            case 'A':
                g[i][j] = 0;
                break;
            case 'C':
                g[i][j] = 1;
                break;
            case 'G':
                g[i][j] = 2;
                break;
            case 'T':
                g[i][j] = 3;
                break;
            default:
                break;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            for (int k = j + 1; k < m; k++)
            {
                bool tab[5][5][5] = {false};
                int l;
                for (l = 0; l < n; l++)
                {
                    tab[g[l][i]][g[l][j]][g[l][k]] = true;
                }
                bool is_ans = true;
                for (; l < 2 * n; l++)
                {
                    if (tab[g[l][i]][g[l][j]][g[l][k]])
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
    return 0;
}