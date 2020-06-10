#include <iostream>
using namespace std;
string c[50];
string b[50];
int ans[50][50];
int main()
{
    int m, f;
    cin >> m >> f;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < f; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < f; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (k == i)
                {
                    continue;
                }
                bool is_child = true;
                for (int l = 0; l < 25; l++)
                {
                    if (b[k][l] != b[i][l] && b[k][l] != c[j][l])
                    {
                        is_child = false;
                        break;
                    }
                }
                if (is_child)
                {
                    ans[i][j]++;
                }
            }
            for (int k = 0; k < f; k++)
            {
                if (k == j)
                {
                    continue;
                }
                bool is_child = true;
                for (int l = 0; l < 25; l++)
                {
                    if (c[k][l] != b[i][l] && c[k][l] != c[j][l])
                    {
                        is_child = false;
                        break;
                    }
                }
                if (is_child)
                {
                    ans[i][j]++;
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < f; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}