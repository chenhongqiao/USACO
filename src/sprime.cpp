#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;
int n;
bool is_prime(long long n)
{
    if (n == 1)
    {
        return false;
    }
    if (n == 2)
    {
        return true;
    }
    for (int i = 2; i <= sqrt(n) + 1; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
void dfs(int dep, long long v)
{
    if (dep >= n)
    {
        cout << v << endl;
        return;
    }
    for (int i = 1; i < 10; i++)
    {
        long long tmp = v * 10 + i;
        if (is_prime(tmp))
        {
            dfs(dep + 1, tmp);
        }
    }
}
int main()
{
    cin >> n;
    dfs(0, 0);
    return 0;
}