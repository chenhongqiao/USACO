#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int testcase, n;
    cin >> testcase >> n;
    const int ans_upperbound = n + 3;
    vector<vector<bool>> states(ans_upperbound, vector<bool>(1 << n, false));
    states[0][0] = 1;
    for (int i = 1; i < ans_upperbound; ++i)
    {
        vector<int> masks;
        for (int j = 0; j < n; ++j)
        {
            int s = 0;
            for (int k = 0; k < i; ++k)
                s ^= 1 << ((j + k) % n);
            masks.push_back(s);
        }
        for (int s = 0; s < (1 << n); ++s)
        {
            if (!states[i - 1][s])
                continue;
            for (int mask : masks)
                states[i][s ^ mask] = true;
        }
    }
    auto shift = [&](int s)
    {
        int t = s >> (n - 1) & 1;
        return ((s << 1) ^ (t << n)) | t;
    };

    while (testcase--)
    {
        auto read = [&]()
        {
            string str;
            cin >> str;
            int s = 0;
            for (int i = 0; i < n; ++i)
                s |= (str[i] - '0') << i;
            return s;
        };
        int light = read();
        int sw = read();
        int cur = light;
        for (int step = 0;; ++step)
        {
            assert(step < ans_upperbound);
            if (states[step][cur])
            {
                cout << step << endl;
                break;
            }
            cur ^= sw;
            sw = shift(sw);
        }
    }
    return 0;
}
