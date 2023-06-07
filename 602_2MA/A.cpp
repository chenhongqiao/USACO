// Circle Game
#include <iostream>
using namespace std;
typedef long long ll;
ll binpow(int a, int b, int p)
{
    ll ans = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
            ans = ans * a % p;
        a = (ll)a * a % p;
    }
    return ans % p;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    cout << (x % n + (m % n) * (binpow(10, k, n))) % n << "\n";
    return 0;
}