// Xor Sum
#include <iostream>
#include <vector>
using namespace std;
long long dfs(long long k, long long s, long long n, vector<long long> &o)
{
    if (k == o.size())
    {
        return 1;
    }
    long long ans = 0;
    if (s + o[k] <= n)
    {
        ans += dfs(k + 1, s + o[k], n, o);
    }
    ans += dfs(k + 1, s, n, o);
    return ans;
}
long long calc(long long n)
{
    long long ans = 0;
    for (long long i = 0; i <= n; i++)
    {
        long long u = i;
        vector<long long> o;
        long long cnt = 1;
        do
        {
            if ((u & 1) == 0)
            {
                o.push_back(1 << cnt);
            }
            cnt++;
            u = u >> 1;
        } while (u > 0);
        ans += dfs(0, i, n, o);
    }
    return ans;
}
int main()
{
    long long n;
    cin >> n;
    cout << calc(n) << endl;
    return 0;
}