/*
ID: harrych3
TASK: gift1
LANG: C++
*/
#include <iostream>
#include <map>
using namespace std;
map<string, int> tmny;
int main()
{
    //decomment following lines when submit
    //freopen("gift1.in","r",stdin);
    //freopen("gift1.out","r",stdout);
    int np;
    cin >> np;
    string name[15];
    for (int i = 0; i < np; i++)
    {
        cin >> name[i];
    }
    for (int i = 0; i < np; i++)
    {
        string ger;
        int m, p;
        cin >> ger;
        cin >> m >> p;
        if (p != 0)
        {
            tmny[ger] -= m;
            tmny[ger] += m % p;
            for (int j = 0; j < p; j++)
            {
                string cer;
                cin >> cer;
                tmny[cer] += m / p;
            }
        }
    }
    for (int i = 0; i < np; i++)
    {
        cout << name[i] << " " << tmny[name[i]] << endl;
    }
    return 0;
}
