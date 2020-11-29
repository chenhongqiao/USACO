#include <bits/stdc++.h>
#define uset unordered_set
using namespace std;
uset<string> d;
uset<string> v;
queue<string> q;
queue<int> l;
int main()
{
    string a;
    string b;
    cin >> a >> b;
    string s;
    while (cin >> s)
    {
        d.insert(s);
    }
    q.push(a);
    l.push(0);
    v.insert(a);
    while (!q.empty())
    {
        string c = q.front();
        for (int i = 0; i < c.size(); i++)
        {
            for (int j = 0; j < 26; j++)
            {
                char tmp = c[i];
                c[i] = 'a' + j;
                if (d.find(c) != d.end() && v.find(c) == d.end())
                {
                    v.insert(c);
                    q.push(c);
                    l.push(l.front() + 1);
                }
                if (c == b)
                {
                    cout << l.front() + 1 << endl;
                    return 0;
                }
                c[i] = tmp;
            }
        }
        q.pop();
        l.pop();
    }
}