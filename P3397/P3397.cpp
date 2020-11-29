#include <iostream>
using namespace std;
int map[1005][1005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        map[x1][y1]++;
        map[x2 + 1][y1]--;
        map[x1][y2 + 1]--;
        map[x2 + 1][y2 + 1]++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            map[i][j] += map[i][j - 1] + map[i - 1][j] - map[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}