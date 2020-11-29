#include <iostream>
#include <algorithm>
using namespace std;
int l[100005];
int main()
{
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    sort(l, l + n);
    int t = n - 1;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (l[i] > s)
        {
            break;
        }
        while (l[t] + l[i] > s)
        {
            t--;
        }
        if (t <= i)
        {
            break;
        }
        ans += t - i;
    }
    cout << ans << endl;
    return EXIT_SUCCESS;
}