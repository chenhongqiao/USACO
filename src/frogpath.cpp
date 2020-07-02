#include <iostream>
using namespace std;
string r;
int l;
int func(int s)
{
    if (r[s] == '#')
    {
        return 0;
    }
    if (s >= l - 2)
    {
        return 1;
    }
    return func(s + 1) + func(s + 2);
}
int main()
{
    cin >> r;
    l = r.size();
    cout << func(0) << endl;
    return 0;
}