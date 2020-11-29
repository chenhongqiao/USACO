#include <iostream>
using namespace std;
void d(int n)
{
    if (n == 1)
    {
        cout << "*" << endl;
        return;
    }
    d(n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    cout << endl;
    d(n - 1);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    cout << endl;
    d(n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    cout << endl;
    return 0;
}