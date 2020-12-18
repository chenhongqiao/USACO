#include <bits/stdc++.h>
using namespace std;
vector<int> w;
bool comp(int a, int b)
{
    return a > b;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        w.push_back(in);
    }
    sort(w.begin(), w.end(), comp);
    for (int i = 0; i < n; i++)
    {
        if (i > w[i])
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}