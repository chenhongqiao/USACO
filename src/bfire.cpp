#include <iostream>
using namespace std;
int r[300];
bool m[300];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        r[i] = i;
    }
    int c = 1;
    int l = 1;
    while (1)
    {
        l += c;
        l %= n;
        if (l == 0)
        {
            l = n;
        }
        if (l == 1)
        {
            cout << c << endl;
            break;
        }
        if (m[r[l]])
        {
            cout << c << endl;
            break;
        }
        m[c] = true;
        int tmp = r[l];
        r[l] = c;
        c = tmp;
    }
    return 0;
}