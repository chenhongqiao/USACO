#include <bits/stdc++.h>
using namespace std;
const int n = 9;
bool r[10][10];
bool c[10][10];
bool b[4][4][10];
int s[10][10];
vector<pair<int, int>> f;
void func(int dep)
{
    if (dep >= f.size())
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << s[i][j] << " ";
            }
            cout << endl;
        }
        exit(0);
    }
    int ci = f[dep].first;
    int cj = f[dep].second;
    for (int i = 1; i <= 9; i++)
    {
        if (!r[ci][i] && !c[cj][i] && !b[ci / 3][cj / 3][i])
        {
            r[ci][i] = true;
            c[cj][i] = true;
            b[ci / 3][cj / 3][i] = true;
            s[ci][cj] = i;
            func(dep + 1);
            s[ci][cj] = 0;
            r[ci][i] = false;
            c[cj][i] = false;
            b[ci / 3][cj / 3][i] = false;
        }
    }
}
int main()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int v;
            cin >> v;
            if (v == 0)
            {
                f.push_back({i, j});
            }
            else
            {
                s[i][j] = v;
                r[i][v] = true;
                c[j][v] = true;
                b[i / 3][j / 3][v] = true;
            }
        }
    }
    func(0);
    cout << "NO SOLUTION" << endl;
    return 0;
}