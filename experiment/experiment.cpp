#include <iostream>
#include <unistd.h>
using namespace std;
void func(long long dep)
{
    if (dep == 260000000)
    {
        cout << "pause" << endl;
        sleep(100);
    }
    func(dep + 1);
}
int main()
{
    cout << "start" << endl;
    func(0);
}