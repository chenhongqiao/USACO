#include <iostream>
#include <algorithm>
using namespace std;
int h[1005];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    int ans = 1000000009;
    for (int i = 17; i <= 117; i++)
    {
        int tmp = 0;
        for (int j = 0; j < n; j++)
        {
            if (h[j] < i - 17)
            {
                tmp += (i - 17 - h[j]) * (i - 17 - h[j]);
            }
            else if (h[j] > i)
            {
                tmp += (h[j] - i) * (h[j] - i);
            }
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}