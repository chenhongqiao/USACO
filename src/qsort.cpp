#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int n;
int partition(const int h, const int t)
{
    int ch = h - 1;
    int ct = t;
    while (ch < ct)
    {
        while (arr[++ch] < arr[t])
        {
        }
        while (ct > 0 && arr[--ct] > arr[t])
        {
        }
        if (ch < ct)
        {
            swap(arr[ch], arr[ct]);
        }
    }
    swap(arr[ch], arr[t]);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return ch;
}
void quicksort(int h, int t)
{

    if (t - h <= 0)
    {
        return;
    }
    int p = partition(h, t);
    quicksort(h, p - 1);
    quicksort(p + 1, t);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    quicksort(0, arr.size() - 1);
    return 0;
}