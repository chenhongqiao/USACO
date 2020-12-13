#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("cowcode.in", "r", stdin);
    //freopen("cowcode.out", "w", stdout);
    string str;
    long long n;
    cin >> str >> n;
    long long k = str.size();
    while (k < n)
    {
        k *= 2;
    }
    while (k >= str.size() * 2)
    {
        if (n == k / 2 + 1)
        {
            n = k / 2;
        }
        else if (n > k / 2)
        {
            n -= (k / 2 + 1);
        }
        k /= 2;
    }
    cout << str[n - 1] << endl;
    return EXIT_SUCCESS;
}