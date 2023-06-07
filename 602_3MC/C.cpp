// Sightseeing Bus
#include <iostream>
#include <vector>
#include <unordered_set>
#define ll long long
using namespace std;
vector<int> arrv[100005];
int lc[100005]; // leave count
int at[100005];
int dt[100005];
int dis[100005];
vector<pair<int, int>> cand;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> dis[i];
    }
    for (int i = 0; i < m; i++)
    {
        int t, a, b;
        cin >> t >> a >> b;
        a--;
        b--;
        arrv[a].push_back(t);
        lc[b]++;
    }
    int t = 0;
    ll tt = 0;
    int pcnt = 0;
    for (int i = 0; i < n; i++)
    {
        at[i] = t;
        for (int j = 0; j < arrv[i].size(); j++)
        {
            t = max(t, arrv[i][j]);
        }
        dt[i] = t;
        for (int j = 0; j < arrv[i].size(); j++)
        {
            tt += t - arrv[i][j];
        }
        tt += (ll)pcnt * (dt[i] - at[i]);
        pcnt += arrv[i].size();
        pcnt -= lc[i];
        tt += (ll)pcnt * dis[i];
        t += dis[i];
    }
    cout << tt << "\n";
    return 0;
}