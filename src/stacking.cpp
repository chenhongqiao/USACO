#include <iostream>
#include <algorithm>
using namespace std;
int stack[1000005];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int h, t;
        cin >> h >> t;
        stack[h]++;
        stack[t + 1]--;
    }
    for (int i = 0; i < n; i++)
    {
        stack[i] += stack[i - 1];
    }
    sort(stack, stack + n);
    cout << stack[n / 2] << endl;
    return 0;
}