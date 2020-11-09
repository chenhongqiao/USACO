#include <bits/stdc++.h>
using namespace std;
vector<int> oni;
vector<int> offi;
vector<string> ans;
int main()
{
    int n, c;
    cin >> n >> c;
    while (1)
    {
        int in;
        cin >> in;
        if (in == -1)
        {
            break;
        }
        oni.push_back(in);
    }
    while (1)
    {
        int in;
        cin >> in;
        if (in == -1)
        {
            break;
        }
        offi.push_back(in);
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                for (int l = 0; l < 2; l++)
                {
                    if (i + j + k + l > c || (i + j + k + l) % 2 != c % 2)
                    {
                        continue;
                    }
                    int s[105] = {0};
                    for (int m = 0; m < n; m++)
                    {
                        s[m] = 1;
                    }

                    if (i == 1)
                    {
                        for (int m = 0; m < n; m++)
                        {
                            s[m] = 1 - s[m];
                        }
                    }
                    if (j == 1)
                    {
                        for (int m = 0; m < n; m += 2)
                        {
                            s[m] = 1 - s[m];
                        }
                    }
                    if (k == 1)
                    {
                        for (int m = 1; m < n; m += 2)
                        {
                            s[m] = 1 - s[m];
                        }
                    }
                    if (l == 1)
                    {
                        for (int m = 0; m * 3 < n; m++)
                        {
                            s[m * 3] = 1 - s[m * 3];
                        }
                    }
                    bool legit = true;
                    for (int m = 0; m < oni.size(); m++)
                    {
                        if (s[oni[m] - 1] != 1)
                        {
                            legit = false;
                            break;
                        }
                    }
                    for (int m = 0; m < offi.size(); m++)
                    {
                        if (s[offi[m] - 1] != 0)
                        {
                            legit = false;
                            break;
                        }
                    }
                    if (legit)
                    {
                        string tmp;
                        for (int m = 0; m < n; m++)
                        {
                            tmp += to_string(s[m]);
                        }
                        ans.push_back(tmp);
                    }
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    if (ans.size() == 0)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}