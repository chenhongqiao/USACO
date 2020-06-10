#include <iostream>
#include <vector>
using namespace std;
vector<int> evev[100005]; //偶数值
vector<int> even[100005]; //编号
vector<int> oddv[100005]; //奇数值
vector<int> oddn[100005]; //编号
long long doe(int c)
{
    if (even[c].size() == 0 || even[c].size() == 1)
    {
        return 0;
    }
    long long tmp = 0;
    for (int i = 0; i < even[c].size(); i++)
    {
        tmp += ((evev[c][i] % 10007) * even[c][i] % 10007) % 10007;
        tmp %= 10007;
    }
    tmp *= (even[c].size() - 2);
    tmp %= 10007;
    long long tmp2 = 0;
    for (int i = 0; i < even[c].size(); i++)
    {
        tmp2 += even[c][i];
        tmp2 %= 10007;
    }
    long long tmp3 = 0;
    for (int i = 0; i < even[c].size(); i++)
    {
        tmp3 += evev[c][i];
        tmp3 %= 10007;
    }
    long long ans = tmp + (tmp2 * tmp3) % 10007;
}
long long doo(int c)
{
    if (oddn[c].size() == 0 || oddn[c].size() == 1)
    {
        return 0;
    }
    long long tmp = 0;
    for (int i = 0; i < oddn[c].size(); i++)
    {
        tmp += ((oddv[c][i] % 10007) * oddn[c][i] % 10007) % 10007;
        tmp %= 10007;
    }
    tmp *= (oddn[c].size() - 2);
    tmp %= 10007;
    long long tmp2 = 0;
    for (int i = 0; i < oddn[c].size(); i++)
    {
        tmp2 += oddn[c][i];
        tmp2 %= 10007;
    }
    long long tmp3 = 0;
    for (int i = 0; i < oddn[c].size(); i++)
    {
        tmp3 += oddv[c][i];
        tmp3 %= 10007;
    }
    long long ans = tmp + (tmp2 * tmp3) % 10007;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int tmp[100005];
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        if (i % 2 == 0)
        {

            evev[c].push_back(tmp[i]);
            even[c].push_back(i);
        }
        else
        {
            oddv[c].push_back(tmp[i]);
            oddn[c].push_back(i);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans += doe(i);
        ans %= 10007;
        ans += doo(i);
        ans %= 10007;
    }
    cout << ans % 10007 << endl;
    return 0;
}