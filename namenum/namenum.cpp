#include <bits/stdc++.h>
using namespace std;
string n;
map<char, int> mp;
vector<string> r;
int main()
{
    mp['A'] = 2;
    mp['B'] = 2;
    mp['C'] = 2;
    mp['D'] = 3;
    mp['E'] = 3;
    mp['F'] = 3;
    mp['G'] = 4;
    mp['H'] = 4;
    mp['I'] = 4;
    mp['J'] = 5;
    mp['K'] = 5;
    mp['L'] = 5;
    mp['M'] = 6;
    mp['N'] = 6;
    mp['O'] = 6;
    mp['P'] = 7;
    mp['R'] = 7;
    mp['S'] = 7;
    mp['T'] = 8;
    mp['U'] = 8;
    mp['V'] = 8;
    mp['W'] = 9;
    mp['X'] = 9;
    mp['Y'] = 9;
    cin >> n;
    string tmp;
    while (cin >> tmp)
    {
        string t;
        for (int i = 0; i < tmp.size(); i++)
        {
            t += mp[tmp[i]] + '0';
        }
        if (n == t)
        {
            r.push_back(tmp);
        }
    }
    sort(r.begin(), r.end());
    for (int i = 0; i < r.size(); i++)
    {
        cout << r[i] << endl;
    }
    if (r.size() == 0)
    {
        cout << "NONE" << endl;
    }
    return 0;
}