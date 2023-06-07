// Moderate Modular Mode
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y;
        cin >> x >> y;
        if (x <= y)
        {
            cout << (y / x * x + y) / 2 << "\n";
        }
        else
        {
            cout << x + y << "\n";
        }
    }
    return 0;
}