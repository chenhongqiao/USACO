#include <bits/stdc++.h>
using namespace std;
vector<pair<bool, int>> s; //true->is mirror, then mi index; false->not mirror, then o number after this;
vector<pair<int, int>> cov;
int n;
void generate(int pos, int dep)
{
    if (pos > n)
    {
        return;
    }
    int ssz = s.size();
    s.push_back({false, dep + 2});
    cov.push_back({pos, pos + dep + 3});
    if (ssz > 0)
    {
        s.push_back({true, ssz});
        cov.push_back({pos + dep + 3, pos * 2 + dep + 3});
    }
    if (ssz > 0)
    {
        generate(pos * 2 + (dep + 3), dep + 1);
    }
    else
    {
        generate(pos + (dep + 3), dep + 1);
    }
}
void printmoo(int m)
{
    cout << "m";
    for (int i = 0; i < m; i++)
    {
        cout << "o";
    }
}
void print(int h, int t)
{
    for (int i = h; i < t; i++)
    {
        if (!s[i].first)
        {
            printmoo(s[i].second);
        }
        else
        {
            print(0, s[i].second);
        }
    }
}

int main()
{
    cin >> n;
    generate(0, 0);
    //print(0, s.size());
    return 0;
}