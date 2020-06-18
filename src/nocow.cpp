#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<string> v[35];
vector<string> no[105];
int d[35][105];
map<string, bool> m[35];
int an = 0;
int nw = 0;
int n, k;
void func(vector<string> t, int dep)
{
    if (dep >= an)
    {
        bool nook = false;
        for (int i = 0; i < n; i++)
        {
            bool match = true;
            for (int j = 0; j < t.size(); j++)
            {
                if (t[j] != no[i][j])
                {
                    match = false;
                }
            }
            if (match)
            {
                nook = true;
                break;
            }
        }
        if (!nook)
        {
            nw++;
            if (nw == k)
            {
                for (int j = 0; j < t.size(); j++)
                {
                    cout << t[j] << " ";
                }
                cout << endl;
                exit(0);
            }
        }
    }
    for (int i = 0; i < v[dep].size(); i++)
    {
        t.push_back(v[dep][i]);
        func(t, dep + 1);
        t.pop_back();
    }
}
int main()
{

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            string trash;
            cin >> trash;
        }
        string tmp;
        an = 0;
        while (1)
        {
            cin >> tmp;
            if (tmp == "cow.")
            {
                break;
            }
            no[i].push_back(tmp);
            if (!m[an][tmp])
            {
                v[an].push_back(tmp);
                m[an][tmp] = true;
            }
            an++;
        }
    }
    for (int i = 0; i < an; i++)
    {
        sort(v[i].begin(), v[i].end());
    }
    vector<string> t;
    func(t, 0);
}