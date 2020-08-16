#include <bits/stdc++.h>
using namespace std;
deque<int> q;
int main()
{
    int s;
    cin >> s;
    int cnt = 1;
    for (int i = 0; i < s; i++)
    {
        char op;
        cin >> op;
        if (op == 'A')
        {
            char d;
            cin >> d;
            if (d == 'L')
            {
                q.push_front(cnt);
                cnt++;
            }
            else if (d == 'R')
            {
                q.push_back(cnt);
                cnt++;
            }
        }
        else if (op == 'D')
        {
            char d;
            int n;
            cin >> d >> n;
            if (d == 'L')
            {
                while (n > 0)
                {
                    q.pop_front();
                    n--;
                }
            }
            else if (d == 'R')
            {
                while (n > 0)
                {
                    q.pop_back();
                    n--;
                }
            }
        }
    }
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop_front();
    }
    return 0;
}