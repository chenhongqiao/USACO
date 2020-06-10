#include <iostream>
using namespace std;
bool tab[105][105][105];
int main()
{
    int n;
    cin >> n;
    int a1, b1, c1;
    int a2, b2, c2;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    int ans = 0;
    for (int i = a1 - 2; i <= a1 + 2; i++)
    {
        for (int j = b1 - 2; j <= b1 + 2; j++)
        {
            for (int k = c1 - 2; k <= c1 + 2; k++)
            {
                int a = (i + n) % n;
                int b = (j + n) % n;
                int c = (k + n) % n;
                if (!tab[a][b][c])
                {
                    ans++;
                    tab[a][b][c] = true;
                }
            }
        }
    }
    for (int i = a2 - 2; i <= a2 + 2; i++)
    {
        for (int j = b2 - 2; j <= b2 + 2; j++)
        {
            for (int k = c2 - 2; k <= c2 + 2; k++)
            {
                int a = (i + n) % n;
                int b = (j + n) % n;
                int c = (k + n) % n;
                if (!tab[a][b][c])
                {
                    ans++;
                    tab[a][b][c] = true;
                }
            }
        }
    }
    cout << ans << endl;
    return EXIT_SUCCESS;
}