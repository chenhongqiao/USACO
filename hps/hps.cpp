#include <bits/stdc++.h>
using namespace std;
vector<char> q;
int pfxsum[100005][3];
int win[3] = {1, 2, 0};
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char tmp;
        cin >> tmp;
        q.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            pfxsum[i][j] = pfxsum[i - 1 > 0 ? i - 1 : 0][j];
        }

        switch (q[i])
        {
        case 'P':
            pfxsum[i][0]++;
            break;
        case 'H':
            pfxsum[i][1]++;
            break;
        case 'S':
            pfxsum[i][2]++;
        default:
            break;
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int tmp = 0;
                tmp += pfxsum[i - 1][win[j]];
                tmp += pfxsum[n - 1][win[k]] - pfxsum[i - 1][win[k]];
                ans = max(ans, tmp);
            }
        }
    }
    cout << ans << endl;
    return 0;
}