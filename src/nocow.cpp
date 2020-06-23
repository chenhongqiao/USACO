#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<string> v[35];
vector<string> no[105];
vector<long long> nol;
long long d[35][105];
map<string, bool> m[35];
int an = 0;
int nw = 0;
int n, k;
int getp(int s)
{
    int p = 0;
    for (int i = 0; i < no[s].size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (no[s][i] == v[i][j])
            {
                p += d[i][j];
            }
        }
    }
    return p;
}
void getans(int dk)
{
    for (int i = 0; i < an; i++)
    {
        for (int j = v[i].size() - 1; j >= 0; j--)
        {
            if (dk > d[i][j])
            {
                if (i < an - 1)
                {
                    cout << v[i][j] << " ";
                }
                else
                {
                    cout << v[i][j];
                }
                dk -= d[i][j];
                break;
            }
        }
    }
}
int main()
{
    freopen("nocow.in", "r", stdin);
    freopen("nocow.out", "w", stdout);
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            string trash;
            cin >> trash;
        }
        string tmp;
        an = 0;
        while (1)
        {
            cin >> tmp;
            if (tmp == "cow.")
            {
                break;
            }
            no[i].push_back(tmp);
            if (!m[an][tmp])
            {
                v[an].push_back(tmp);
                m[an][tmp] = true;
            }
            an++;
        }
    }
    for (int i = 0; i < an; i++)
    {
        sort(v[i].begin(), v[i].end());
    }
    for (int i = 1; i < v[an - 1].size(); i++)
    {
        d[an - 1][i] = i;
    }

    for (int i = an - 2; i >= 0; i--)
    {
        for (int j = 1; j < v[i].size(); j++)
        {
            d[i][j] = d[i][j - 1] + d[i + 1][1] * v[i + 1].size();
        }
        if (v[i].size() <= 1)
        {
            d[i][1] = d[i + 1][1] * v[i + 1].size();
        }
    }
    for (int i = 0; i < an - 2; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            // cout << d[i][j] << " ";
        }
        // cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        nol.push_back(getp(i));
    }
    sort(nol.begin(), nol.end());

    for (int i = 0; i < n; i++)
    {
        if (nol[i] < k)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    getans(k);
    return 0;
}