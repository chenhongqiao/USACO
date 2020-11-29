#include <bits/stdc++.h>
using namespace std;
int cap[3];
int m[3];
bool v[25][25][25];
set<int> ans;
void func(int dep)
{
    if (v[m[0]][m[1]][m[2]])
    {
        return;
    }
    if (m[0] == 0)
    {
        ans.insert(m[2]);
    }
    v[m[0]][m[1]][m[2]] = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int mv = min(m[i], cap[j] - m[j]);
            m[i] -= mv;
            m[j] += mv;
            func(dep + 1);
            m[i] += mv;
            m[j] -= mv;
        }
    }
}
int main()
{
    cin >> cap[0] >> cap[1] >> cap[2];
    m[2] = cap[2];
    func(0);
    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}