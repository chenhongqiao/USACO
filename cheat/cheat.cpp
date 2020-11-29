#include <bits/stdc++.h>
using namespace std;
deque<int> c;
vector<int> ans;
int main()
{
    int n, k, p;
    cin >> n >> k >> p;
    for (int i = 1; i <= k; i++)
    {
        c.push_back(i);
    }
    int nc = 1;
    while (!c.empty())
    {
        if (nc % n == 0)
        {
            ans.push_back(c.front());
            c.pop_front();
            nc++;
        }
        else
        {
            c.pop_front();
            nc++;
        }
        for (int i = 0; i < p; i++)
        {
            c.push_back(c.front());
            c.pop_front();
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}