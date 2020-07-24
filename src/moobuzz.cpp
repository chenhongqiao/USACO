#include <iostream>
using namespace std;
bool s[15] = {true, true, false, true, false, false, true, true, false, false, true, false, true, true, false};
int main()
{
    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);
    int n;
    cin >> n;
    int ps = 15 * (n / 8);
    n %= 8;
    if (n == 0)
    {
        ps--;
    }
    int i;
    for (i = 0; n > 0; i++)
    {
        if (s[i])
        {
            n--;
        }
    }
    cout << ps + i << endl;
    return 0;
}
