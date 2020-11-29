#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> t1(50005);
vector<int> t2(50005);
char str[50005];
vector<char> supp[50005];
int main()
{
    //freopen("read.in", "r", stdin);
    char tmp;
    int n = 0;
    while (1)
    {
        tmp = getchar();
        if (tmp == EOF)
        {
            break;
        }
        if (tmp >= 'a' && tmp <= 'z' || tmp >= 'A' && tmp <= 'Z')
        {
            str[n] = tmp;
            n++;
        }
        else
        {
            supp[n].push_back(tmp);
        }
    }

    int l = 0, r = -1;
    int ans = 0;
    int anssub;
    int anst;
    for (int i = 0; i < n; i++)
    {
        int k = 1;
        if (i <= r)
        {
            k = min(t1[l + r - i], r - i);
        }
        while (i + k < n && i - k >= 0 && tolower(str[i - k]) == tolower(str[i + k]))
        {
            k++;
        }
        k--;
        t1[i] = k;
        if (t1[i] * 2 + 1 > ans)
        {
            ans = t1[i] * 2 + 1;
            anssub = i;
            anst = 1;
        }
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }
    l = 0, r = -1;
    for (int i = 0; i < n; i++)
    {
        int k = 1;
        if (i <= r)
        {
            k = min(t2[l + r - i + 1], r - i + 1);
        }
        while (i + k < n && i - k - 1 >= 0 && tolower(str[i - k - 1]) == tolower(str[i + k]))
        {
            k++;
        }
        k--;
        t2[i] = k;
        if (t2[i] * 2 > ans)
        {
            ans = t2[i] * 2 + 2;
            anssub = i;
            anst = 2;
        }
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }
    cout << ans << endl;
    if (ans != 0)
    {
        if (anst == 1)
        {
            for (int i = anssub - t1[anssub]; i <= anssub + t1[anssub]; i++)
            {
                if (i != anssub - t1[anssub] && !supp[i].empty())
                {
                    for (int j = 0; j < supp[i].size(); j++)
                    {
                        cout << supp[i][j];
                    }
                }
                cout << str[i];
            }
            cout << endl;
        }
        if (anst == 2)
        {
            for (int i = anssub - t2[anssub] - 1; i <= anssub + t2[anssub]; i++)
            {
                if (i != anssub - t2[anssub] - 1 && !supp[i].empty())
                {
                    for (int j = 0; j < supp[i].size(); j++)
                    {
                        cout << supp[i][j];
                    }
                }
                cout << str[i];
            }
            cout << endl;
        }
    }
    return EXIT_SUCCESS;
}