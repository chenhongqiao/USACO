#include <iostream>
#include <stack>
using namespace std;
stack<int> a, b, c;
int main()
{
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--)
    {
        a.push(i);
    }
    int w, d;
    while (cin >> w >> d)
    {
        if (w == 1)
        {
            for (int i = 0; i < d; i++)
            {
                b.push(a.top());
                a.pop();
            }
        }
        else if (w == 2)
        {
            for (int i = 0; i < d; i++)
            {
                c.push(b.top());
                b.pop();
            }
        }
    }
    for (int i = 0; !c.empty(); i++)
    {
        cout << c.top() << endl;
        c.pop();
    }
    return 0;
}