#include <iostream>
#include <algorithm>
#include <unordered_map>
#define umap unordered_map
using namespace std;
umap<int, umap<int, umap<int, umap<int, umap<int, int>>>>> s5;
umap<int, umap<int, umap<int, umap<int, int>>>> s4;
umap<int, umap<int, umap<int, int>>> s3;
umap<int, umap<int, int>> s2;
umap<int, int> s1;
int c[50005][5];
void build_s1(int s[])
{
    for (int i = 0; i < 5; i++)
    {
        s1[s[i]]++;
    }
}
void build_s2(int s[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            s2[s[i]][s[j]]++;
        }
    }
}
void build_s3(int s[])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            for (int k = j + 1; k < 5; k++)
            {
                s3[s[i]][s[j]][s[k]]++;
            }
        }
    }
}
void build_s4(int s[])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            for (int k = j + 1; k < 4; k++)
            {
                for (int l = k + 1; l < 5; l++)
                {
                    s4[s[i]][s[j]][s[k]][s[l]]++;
                }
            }
        }
    }
}
void build_s5(int s[])
{
    s5[s[0]][s[1]][s[2]][s[3]][s[4]]++;
}
int get_s1(int s[])
{
    int ans = 0;
    for (int i = 0; i < 5; i++)
    {
        ans += s1[s[i]];
    }
    return ans;
}
int get_s2(int s[])
{
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            ans += s2[s[i]][s[j]];
        }
    }
    return ans;
}
int get_s3(int s[])
{
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            for (int k = j + 1; k < 5; k++)
            {
                ans += s3[s[i]][s[j]][s[k]];
            }
        }
    }
    return ans;
}
int get_s4(int s[])
{
    int ans = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            for (int k = j + 1; k < 4; k++)
            {
                for (int l = k + 1; l < 5; l++)
                {
                    ans += s4[s[i]][s[j]][s[k]][s[l]];
                }
            }
        }
    }
    return ans;
}
int get_s5(int s[])
{
    return s5[s[0]][s[1]][s[2]][s[3]][s[4]];
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> c[i][j];
        }
        sort(c[i], c[i] + 5);
        build_s1(c[i]);
        build_s2(c[i]);
        build_s3(c[i]);
        build_s4(c[i]);
        build_s5(c[i]);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (get_s1(c[i]) - get_s2(c[i]) + get_s3(c[i]) - get_s4(c[i]) + get_s5(c[i]));
    }
    cout << ((long long)n * n - ans) / 2 << endl;
    return 0;
}
