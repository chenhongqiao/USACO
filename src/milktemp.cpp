#include <iostream>
#include <algorithm>

#include <vector>
using namespace std;
vector<pair<int, bool>> s;
int main()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    for (int i = 0; i < n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        s.push_back({t1, false});
        s.push_back({t2, true});
    }
    sort(s.begin(), s.end());
    int cx = n, cy = 0, cz = 0;
    int ans = cx * x;
    for (int i = 0; i < 2 * n; i++)
    {
        //cout << cx << " " << cy << " " << cz << endl;
        if (!s[i].second)
        {
            cy++;
            cx--;
        }
        else
        {
            cz++;
            cy--;
        }
        ans = max(ans, cx * x + cy * y + cz * z);
    }
    cout << ans << endl;

    return 0;
}