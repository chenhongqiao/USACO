// Guess the Permutation
#include <iostream>
#define ll long long
using namespace std;
ll query(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    ll x;
    cin >> x;
    return x;
}
void answer(int i, int j, int k)
{
    cout << "! " << i << " " << j << " " << k << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int l = 1;
        int r = n;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (query(1, mid) == 0)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        int i = l;
        int j = i + query(i, n) - query(i + 1, n) + 1;
        int k = j + query(j, n) - query(j + 1, n);
        answer(i, j, k);
    }
    return 0;
}