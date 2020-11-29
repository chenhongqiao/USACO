#include <iostream>
#include <utility>
#include <vector>
using namespace std;
struct node
{
    vector<pair<char, int>> son;
} nd[600005];
int num = 0;
void add(int fa, int sub, string str)
{
    if (sub >= str.size())
    {
        return;
    }
    for (int i = 0; i < nd[fa].son.size(); i++)
    {
        if (nd[fa].son[i].first == str[sub])
        {
            return add(nd[fa].son[i].second, sub + 1, str);
        }
    }
    nd[fa].son.push_back(make_pair(str[sub], num));
    return add(num++, sub + 1, str);
}
bool check(int fa, int sub, string str)
{
    if (sub >= str.size())
    {
        return true;
    }
    for (int i = 0; i < nd[fa].son.size(); i++)
    {
        if (nd[fa].son[i].first == str[sub])
        {
            return check(nd[fa].son[i].second, sub + 1, str);
        }
    }
    return false;
}
int main()
{
    int n, m;
    cin >> m >> n;
    cin.ignore();
    for (int i = 0; i < m; i++)
    {
        string str;
        getline(std::cin, str);
        add(0, 0, str);
    }
    /*for (int i = 0; i < num; i++)
    {
        cout << i << endl;
        for (int j = 0; j < nd[i].son.size(); j++)
        {
            cout << nd[i].son[j].first << " " << nd[i].son[j].second << endl;
        }
    }*/
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(std::cin, str);
        if (check(0, 0, str))
        {
            ans++;
        }
    }
    cout << ans << endl;
    return EXIT_SUCCESS;
}