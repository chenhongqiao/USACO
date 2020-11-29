#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    while (n > 2)
    {
        if (n / 3 * 3 == n)
        {
            cnt++;
            n /= 3;
        }
        else if (n * 1.0 / 3 - n / 3 > 0.5)
        {
            n++;
            cnt++;
        }
        else
        {
            n--;
            cnt++;
        }
    }
    if (n == 2)
    {
        cnt++;
        n--;
    }
    cout << cnt << endl;
    return 0;
}