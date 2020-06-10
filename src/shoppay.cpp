#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int> q;
vector<int> ans[50];
int main()
{
    int n;
    cin >> n;
    char o;
    int v;
    while (cin >> o >> v)
    {
        if (o == 'C')
        {
            q.push(v);
        }
        else
        {
            if (!q.empty())
            {
                ans[v].push_back(q.front());
                q.pop();
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i].size() << " ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}