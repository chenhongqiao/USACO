// Solving Equations
#include <iostream>
#include <vector>
using namespace std;
const int LEN = 500;
int a[105][LEN];
bool neg[105];
vector<int> ans;
void add(int a[], int b[], int c[])
{
    for (int i = 0; i < LEN; ++i)
    {
        c[i] += a[i] + b[i];
        if (c[i] >= 10)
        {
            c[i + 1] += 1;
            c[i] -= 10;
        }
    }
}
void sub(int a[], int b[], int c[])
{
    for (int i = 0; i < LEN; ++i)
    {
        c[i] += a[i] - b[i];
        if (c[i] < 0)
        {
            c[i + 1] -= 1;
            c[i] += 10;
        }
    }
}

void mul_short(int a[], int b, int c[])
{
    for (int i = 0; i < LEN; ++i)
    {
        c[i] += a[i] * b;

        if (c[i] >= 10)
        {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
}
void mul(int a[], int b[], int c[])
{
    for (int i = 0; i < LEN; ++i)
    {
        for (int j = 0; j <= i; ++j)
            c[i] += a[j] * b[i - j];

        if (c[i] >= 10)
        {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
}
bool verify(int n, int m)
{
    int accm[LEN] = {0};
    int v[LEN] = {0};
    v[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int x[LEN] = {0};
        mul(a[i], v, x);
        int y[LEN] = {0};
        if (!neg[i])
        {
            add(x, accm, y);
        }
        else
        {
            sub(accm, x, y);
        }
        for (int i = 0; i < LEN; i++)
        {
            accm[i] = y[i];
        }
        int z[LEN] = {0};
        mul_short(v, m, z);
        for (int i = 0; i < LEN; i++)
        {
            v[i] = z[i];
        }
    }
    for (int i = 0; i < LEN; i++)
    {
        if (accm[i] != 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    n += 1;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s[0] == '-')
        {
            neg[i] = true;
            for (int j = 1; j < s.size(); j++)
            {
                a[i][j - 1] = s[j] - '0';
            }
        }
        else
        {
            for (int j = 0; j < s.size(); j++)
            {
                a[i][j] = s[j] - '0';
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (verify(n, i))
        {
            ans.push_back(i);
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}