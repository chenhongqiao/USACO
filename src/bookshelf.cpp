#include <iostream>
#include <algorithm>
using namespace std;
int h[20005];
bool cmp(const int &a, const int &b)
{
    return a > b;
}
int main()
{
    int n, b;
    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    sort(h, h + n, cmp);
    long long ch = 0;
    for (int i = 0; i < n; i++)
    {
        ch += h[i];
        if (ch >= b)
        {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}