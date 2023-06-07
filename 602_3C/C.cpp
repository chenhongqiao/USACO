// Median Pyramid Hard
#include <iostream>
#include <vector>
using namespace std;
bool check(vector<int> &a, int v)
{
    int p = a.size() / 2;
    for (int i = 0; i < p; i++)
    {
        if (a[p - i] >= v && a[p - i - 1] >= v)
        {
            return true;
        }
        if (a[p + i] >= v && a[p + i + 1] >= v)
        {
            return true;
        }
        if (a[p - i] < v && a[p - i - 1] < v)
        {
            return false;
        }
        if (a[p + i] < v && a[p + i + 1] < v)
        {
            return false;
        }
    }
    return a[0] >= v;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(2 * n - 1);
    for (auto &i : a)
    {
        cin >> i;
    }
    int l = 1;
    int r = 2 * n - 1;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(a, mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << l << "\n";
    return 0;
}