#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int n;
void merge(int sa, int ea, int sb, int eb)
{
    vector<int> arrc;
    int ha = sa;
    int hb = sb;
    while (ha <= ea && hb <= eb)
    {
        while (ha <= ea && arr[ha] <= arr[hb])
        {
            arrc.push_back(arr[ha]);
            ha++;
        }
        while (hb <= eb && arr[hb] < arr[ha])
        {
            arrc.push_back(arr[hb]);
            hb++;
        }
    }
    while (ha <= ea)
    {
        arrc.push_back(arr[ha]);
        ha++;
    }
    while (hb <= eb)
    {
        arrc.push_back(arr[hb]);
        hb++;
    }
    int j = 0;
    for (int i = sa; i <= eb; i++)
    {
        arr[i] = arrc[j];
        j++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void msort(int h, int t)
{
    if (t - h < 1)
    {
        return;
    }
    msort(h, h + (t - h) / 2);
    msort(h + (t - h) / 2 + 1, t);
    merge(h, h + (t - h) / 2, h + (t - h) / 2 + 1, t);
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
    msort(0, n - 1);

    return 0;
}