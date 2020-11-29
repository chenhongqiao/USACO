#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> s;
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        s.push_back(tmp);
    }
    for (int i = 0; i < q; i++)
    {
        int op;
        cin >> op;
        int l = lower_bound(s.begin(), s.end(), op) - s.begin();
        if (l >= s.size() || s[l] != op)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << l << endl;
        }
    }
    return 0;
}