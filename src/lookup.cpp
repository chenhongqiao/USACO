#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
stack<int> sv;
int cow[1000005];
int ans[1000005];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cow[i];
    }
    sv.push(n - 1);
    ans[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (cow[i] < cow[sv.top()])
        {
            ans[i] = sv.top() + 1;
            sv.push(i);
        }
        else
        {
            while (!sv.empty() && cow[i] >= cow[sv.top()])
            {
                sv.pop();
            }
            if (sv.empty())
            {
                ans[i] = 0;
            }
            else
            {
                ans[i] = sv.top() + 1;
            }
            sv.push(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}