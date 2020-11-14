#include <bits/stdc++.h>
#define umap unordered_map
using namespace std;
vector<string> istn;
int n;
pair<int, int> f[4];
umap<string, int> mp;
umap<string, pair<int, int>> mv;
int xmax = -200000, xmin = +200000;
int ymax = -200000, ymin = +200000;
int cnt = 0;
void record()
{
    for (int i = 0; i < 4; i++)
    {
        xmax = max(xmax, f[i].first);
        xmin = min(xmin, f[i].first);
        ymax = max(ymax, f[i].second);
        ymin = min(ymin, f[i].second);
    }
}
void swapi()
{
    auto pf = mv["F"];
    auto pb = mv["B"];
    auto pl = mv["L"];
    auto pr = mv["R"];
    mv["F"] = pr;
    mv["B"] = pl;
    mv["L"] = pf;
    mv["R"] = pb;
}
void func(int dep)
{
    record();
    if (dep >= n)
    {
        return;
    }
    if (istn[dep][2] != 'P')
    {
        pair<int, int> *cm = &mv[istn[dep].substr(2, 1)];
        pair<int, int> *cf = &f[mp[istn[dep].substr(0, 2)]];
        cf->first += cm->first;
        cf->second += cm->second;
    }
    else
    {
        auto pf = f[mp[istn[dep].substr(0, 2)]];
        for (int i = 0; i < 4; i++)
        {
            int tmp = f[i].first;
            f[i].first = pf.first + (f[i].second - pf.second);
            f[i].second = pf.second - (tmp - pf.first);
        }
        swapi();
    }
    func(dep + 1);
}

void init()
{
    mp["FL"] = 0;
    mp["FR"] = 1;
    mp["RL"] = 2;
    mp["RR"] = 3;
    f[mp["FR"]] = {0, 0};
    f[mp["FL"]] = {-1, 0};
    f[mp["RR"]] = {0, -1};
    f[mp["RL"]] = {-1, -1};
    mv["F"] = {0, +1};
    mv["B"] = {0, -1};
    mv["R"] = {+1, 0};
    mv["L"] = {-1, 0};
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string in;
        cin >> in;
        istn.push_back(in);
    }
    init();
    func(0);
    cout << (xmax - xmin + 1) * (ymax - ymin + 1) << endl;
    return 0;
}