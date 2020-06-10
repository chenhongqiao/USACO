#include <iostream>
using namespace std;
int suma[30005];
int sumb[30005];
int main()
{

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        suma[i] = suma[i - 1];
        sumb[i] = sumb[i - 1];
        if (tmp == 1)
        {
            suma[i]++;
        }
        else
        {
            sumb[i]++;
        }
    }
    int ans = 1000000000;
    for (int i = 0; i <= n; i++)
    {
        ans = min(ans, sumb[i] + suma[n] - suma[i]);
    }
    cout << ans << endl;
    return 0;
}