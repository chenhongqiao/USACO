#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(const int &a, const int &b)
{
    return a > b;
}
int main()
{
    int n;
    int w[100005];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    sort(w, w + n, cmp);
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (i > w[i])
        {
            ans = i;
            break;
        }
    }
    if (ans == -1)
    {
        cout << n << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}