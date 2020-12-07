#include <bits/stdc++.h>
#define rand(l, h) (rand() % (h - l + 1) + l)
using namespace std;
unordered_map<string, int> m = {{"Rock", 0}, {"Paper", 1}, {"Scissors", 2}};
int beat[3] = {2, 0, 1};
int main()
{
    while (1)
    {
        cout << "Rock, Paper, or Scissors?" << endl;
        srand(time(0));
        int cc = rand(0, 2);
        string in;
        cin >> in;
        if (m.find(in) == m.end())
        {
            cout << "Invalid input" << endl;
            continue;
        }
        int uc = m[in];
        if (uc == cc)
        {
            cout << "Tie" << endl;
        }
        else if (beat[uc] == cc)
        {
            cout << "You win" << endl;
        }
        else if (beat[cc] == uc)
        {
            cout << "You lost" << endl;
        }
    }
    return 0;
}