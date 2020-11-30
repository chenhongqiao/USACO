#include <bits/stdc++.h>
using namespace std;
vector<int> h;
vector<int> s;
vector<int> a;
int main()
{
    //freopen("homework.in", "r", stdin);
    //freopen("homework.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        h.push_back(tmp);
        s.push_back(tmp);
    }
    sort(s.begin(), s.end());
    int sum = 0;
    int ln = n;
    for (int i = 0; i < n; i++)
    {
        sum += h[i];
    }
    double ans = 1.0 * (sum - s[0]) / (ln - 1);
    for (int i = 0; i < n - 2; i++)
    {
        int k = h[i];
        ln--;
        sum -= k;
        s.erase(lower_bound(s.begin(), s.end(), k));
        double p = 1.0 * (sum - s[0]) / (ln - 1);
        if (p > ans)
        {
            a.clear();
            a.push_back(i);
            ans = p;
        }
        else if (p == ans)
        {
            a.push_back(i);
        }
    }
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] + 1 << endl;
    }
    return 0;
}