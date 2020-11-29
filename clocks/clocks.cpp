#include <bits/stdc++.h>
#define uset unordered_set
using namespace std;
queue<string> q;
queue<vector<int>> l;
uset<string> v;
int m[9][5] = {{0, 1, 3, 4}, {0, 1, 2}, {1, 2, 4, 5}, {0, 3, 6}, {1, 3, 4, 5, 7}, {2, 5, 8}, {3, 4, 6, 7}, {6, 7, 8}, {4, 5, 7, 8}};
int ms[9] = {4, 3, 4, 3, 5, 3, 4, 3, 4};
int main()
{
    string b;
    for (int i = 0; i < 9; i++)
    {
        int in;
        cin >> in;
        b.push_back((in / 3) + '0');
    }
    q.push(b);
    v.insert(b);
    vector<int> bv;
    l.push(bv);
    while (!q.empty())
    {
        bool is_ans = true;
        for (int i = 0; i < q.front().size(); i++)
        {
            if (q.front()[i] != '4')
            {
                is_ans = false;
                break;
            }
        }
        if (is_ans)
        {
            break;
        }
        for (int i = 0; i < 9; i++)
        {
            string c = q.front();
            for (int j = 0; j < ms[i]; j++)
            {
                c[m[i][j]] += 1;
                if (c[m[i][j]] > '4')
                {
                    c[m[i][j]] -= 4;
                }
            }
            if (v.find(c) == v.end())
            {
                v.insert(c);
                q.push(c);
                vector<int> cl = l.front();
                cl.push_back(i);
                l.push(cl);
            }
        }
        q.pop();
        l.pop();
    }
    for (int i = 0; i < l.front().size(); i++)
    {
        cout << l.front()[i] + 1 << " ";
    }
    cout << endl;
}