#include <bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int> arra, vector<int> arrb)
{
    vector<int> arrc;
    int ha = 0;
    int hb = 0;
    while (ha < arra.size() && hb < arrb.size())
    {
        while (ha < arra.size() && arra[ha] <= arrb[hb])
        {
            arrc.push_back(arra[ha]);
            ha++;
        }
        while (hb < arrb.size() && arrb[hb] < arra[ha])
        {
            arrc.push_back(arrb[hb]);
            hb++;
        }
    }
    while (ha < arra.size())
    {
        arrc.push_back(arra[ha]);
        ha++;
    }
    while (hb < arrb.size())
    {
        arrc.push_back(arrb[hb]);
        hb++;
    }
    return arrc;
}
vector<int> msort(vector<int> arr)
{
    if (arr.size() == 1)
    {
        return arr;
    }
    vector<int> left;
    vector<int> right;
    for (int i = 0; i < arr.size() / 2; i++)
    {
        left.push_back(arr[i]);
    }
    for (int i = arr.size() / 2; i < arr.size(); i++)
    {
        right.push_back(arr[i]);
    }
    return merge(msort(left), msort(right));
}
int main()
{
    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    vector<int> ans = msort(arr);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}