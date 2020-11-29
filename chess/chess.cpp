#include <iostream>
using namespace std;
int n, k;
int ow = 0;
char c[2005][2005];
int fc[2005][2005];
int sc[2005][2005];
int fr[2005][2005];
int sr[2005][2005];
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        bool w = true;
        for (int j = 0; j < n; j++)
        {
            if (c[i][j] != 'W')
            {
                w = false;
                break;
            }
        }
        if (w)
        {
            ow++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        bool w = true;
        for (int j = 0; j < n; j++)
        {
            if (c[j][i] != 'W')
            {
                w = false;
                break;
            }
        }
        if (w)
        {
            ow++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > 0)
            {
                fr[i][j] = fr[i][j - 1];
            }
            if (c[i][j] == 'B')
            {
                fr[i][j]++;
            }
        }
    }
    for (int i = 0; i < n - k + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > 0)
            {
                sr[i][j] = sr[i][j - 1];
            }
            if (i > 0)
            {
                if (fr[j][i + k - 1] - fr[j][i - 1] == fr[j][n - 1] && fr[j][n - 1] != 0)
                {
                    sr[i][j]++;
                }
            }
            else
            {
                if (fr[j][i + k - 1] == fr[j][n - 1] && fr[j][n - 1] != 0)
                {
                    sr[i][j]++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > 0)
            {
                fc[i][j] = fc[i][j - 1];
            }
            if (c[j][i] == 'B')
            {
                fc[i][j]++;
            }
        }
    }
    for (int i = 0; i < n - k + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > 0)
            {
                sc[i][j] = sc[i][j - 1];
            }
            if (i > 0)
            {
                if (fc[j][i + k - 1] - fc[j][i - 1] == fc[j][n - 1] && fc[j][n - 1] != 0)
                {
                    sc[i][j]++;
                }
            }
            else
            {
                if (fc[j][i + k - 1] == fc[j][n - 1] && fc[j][n - 1] != 0)
                {
                    sc[i][j]++;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n - k + 1; i++)
    {
        for (int j = 0; j < n - k + 1; j++)
        {
            int tmp1, tmp2;
            if (i > 0)
            {
                tmp1 = sr[j][i + k - 1] - sr[j][i - 1];
            }
            else
            {
                tmp1 = sr[j][i + k - 1];
            }
            if (j > 0)
            {
                tmp2 = sc[i][j + k - 1] - sc[i][j - 1];
            }
            else
            {
                tmp2 = sc[i][j + k - 1];
            }
            ans = max(ans, tmp1 + tmp2);
        }
    }
    cout << ans + ow << endl;

    return 0;
}