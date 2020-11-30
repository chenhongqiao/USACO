#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> cp;
map<int, int> p;
struct measurement
{
    int d, id, k;
};
vector<measurement> m;
bool comp(const measurement &a, const measurement &b)
{
    return a.d < b.d;
}
int main()
{
    //freopen("measurement.in", "r", stdin);
    //freopen("measurement.out", "w", stdout);
    int n, g;
    cin >> n >> g;
    for (int i = 0; i < n; i++)
    {
        int d, id, k;
        cin >> d >> id >> k;
        m.push_back({d, id, k});
    }
    sort(m.begin(), m.end(), comp);
    int ans = 0;
    p[g] = n;
    for (int i = 0; i < n; i++)
    {
        int kp;
        if (cp.find(m[i].id) != cp.end())
        {
            kp = cp[m[i].id];
        }
        else
        {
            kp = g;
        }
        auto top = p.rbegin();
        if (kp <= top->first && kp + m[i].k > top->first && (kp != top->first || top->second != 1))
        {
            ans++;
        }
        else if (kp < top->first && kp + m[i].k == top->first)
        {
            ans++;
        }
        else if (kp == top->first && kp + m[i].k < top->first && top->second != 1)
        {
            ans++;
        }
        else if (kp == top->first && kp + m[i].k < top->first)
        {
            for (auto it = p.rbegin(); it != p.rend(); it++)
            {
                if (it->second > 0 && it->first != kp && it->first >= kp + m[i].k)
                {
                    ans++;
                    break;
                }
                if (it->first < kp + m[i].k)
                {
                    break;
                }
            }
        }
        p[kp + m[i].k]++;
        p[kp]--;
        if (p[kp] == 0)
        {
            p.erase(kp);
        }
        cp[m[i].id] = kp + m[i].k;
    }
    cout << ans << endl;
    return 0;
}