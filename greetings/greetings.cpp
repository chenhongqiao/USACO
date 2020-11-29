#include <iostream>
using namespace std;
struct bessie
{
    int v;
    char o;
} B[50005];
struct elsie
{
    int v;
    char o;
} E[50005];

int main()
{
    int b, e;
    cin >> b >> e;
    for (int i = 0; i < b; i++)
    {
        cin >> B[i].v >> B[i].o;
    }
    for (int i = 0; i < e; i++)
    {
        cin >> E[i].v >> E[i].o;
    }
    int bl = 0, el = 0;
    int bh = 0, eh = 0;
    bool p = false;
    int ans = 0;
    for (int i = 0;; i++)
    {
        if (p && bl == el)
        {
            ans++;
            p = false;
        }
        if (bl != el)
        {
            p = true;
        }
        if (bh < b)
        {
            if (B[bh].o == 'L')
            {
                bl--;
                B[bh].v--;
                if (B[bh].v <= 0)
                {
                    bh++;
                }
            }
            else if (B[bh].o == 'R')
            {
                bl++;
                B[bh].v--;
                if (B[bh].v <= 0)
                {
                    bh++;
                }
            }
        }
        if (eh < e)
        {
            if (E[eh].o == 'L')
            {
                el--;
                E[eh].v--;
                if (E[eh].v <= 0)
                {
                    eh++;
                }
            }
            else if (E[eh].o == 'R')
            {
                el++;
                E[eh].v--;
                if (E[eh].v <= 0)
                {
                    eh++;
                }
            }
        }
        if (bh >= b && eh >= e)
        {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}