#include <iostream>

using namespace std;

int mdays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int n;
    cin >> n;
    int cnt[8] = {0};
    int y = 1900, m = 1, dt = 1, dy = 1;
    while (y - 1900 < n)
    {
        if (dt == 13)
        {
            cnt[dy]++;
        }
        dt++;
        dy++;
        if (dy > 7)
        {
            dy = 1;
        }
        if (((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) && m == 2)
        {
            if (dt > 29)
            {
                m += 1;
                dt = 1;
            }
        }
        else
        {
            if (dt > mdays[m])
            {
                m += 1;
                dt = 1;
            }
            if (m > 12)
            {
                y += 1;
                m = 1;
            }
        }
    }
    cout << cnt[6] << " " << cnt[7] << " " << cnt[1] << " "
         << cnt[2] << " " << cnt[3] << " " << cnt[4] << " " << cnt[5] << " " << endl;
    return 0;
}