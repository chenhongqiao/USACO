#include <iostream>
using namespace std;
struct guess
{
    char t[5];
    int c, w;
} g[105];
bool match(char can[5], char o[5], int nc, int nw)
{
    int c = 0, w = 0;
    for (int i = 0; i < 4; i++)
    {
        //cout << o[i] << " ";
    }
    //cout << endl;

    for (int i = 0; i < 4; i++)
    {
        if (can[i] == o[i] - '0')
        {
            c++;
        }
    }
    int tab[100] = {0};
    for (int i = 0; i < 4; i++)
    {
        tab[o[i] - '0']++;
    }
    for (int i = 0; i < 4; i++)
    {
        if (tab[can[i]])
        {
            tab[can[i]]--;
            w++;
        }
    }
    w -= c;
    w = max(0, w);
    //cout << c << " " << w << endl;
    if (nc == c && nw == w)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> g[i].t >> g[i].c >> g[i].w;
    }
    bool has_ans = false;
    for (int i = 1000; i <= 9999; i++)
    {
        int tmp = i;
        char t[5];
        for (int j = 3; j >= 0; j--)
        {
            t[j] = tmp % 10;
            tmp /= 10;
        }
        bool is_ans = true;
        for (int j = 0; j < n; j++)
        {
            if (!match(t, g[j].t, g[j].c, g[j].w))
            {
                is_ans = false;
                break;
            }
        }
        if (is_ans)
        {
            has_ans = true;
            cout << i << endl;
            break;
        }
    }
    if (!has_ans)
    {
        cout << "NONE" << endl;
    }
    return EXIT_SUCCESS;
}