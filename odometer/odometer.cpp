#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long min, max;
    cin >> min >> max;
    int minl = 0;
    int maxl = 0;
    long long tmp = min;
    while (tmp > 0)
    {
        tmp /= 10;
        minl++;
    }
    tmp = max;
    while (tmp > 0)
    {
        tmp /= 10;
        maxl++;
    }
    map<long long, bool> v;
    int ans = 0;
    //cout << minl << " " << maxl << endl;
    for (int i = minl; i <= maxl; i++) //Interesting number length
    {
        for (int j = 0; j <= 9; j++) //Repetive diget
        {
            for (int k = 0; k <= 9; k++) //Different digit
            {
                if (j == k)
                {
                    continue;
                }
                for (int l = 0; l < i; l++) //Diffrent digit position
                {
                    if (k == l && l == 0)
                    {
                        continue;
                    }
                    long long n = 0;
                    for (int m = 0; m < i; m++)
                    {
                        n *= 10;
                        if (m == l)
                        {
                            n += k;
                        }
                        else
                        {
                            n += j;
                        }
                    }

                    if (n >= min && n <= max && !v[n])
                    {
                        //cout << n << endl;
                        ans++;
                        v[n] = true;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}