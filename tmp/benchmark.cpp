//Warning: This code only compat with C++11 or higher
#include<iostream>
#include<chrono>
using namespace std;
int main()
{
    auto begin = chrono::high_resolution_clock::now();
    register long long int tmp=0;
    for(register long long i=0;i<10000000000;i++){
        tmp++;
        tmp--;
        tmp++;
    }
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(chrono::high_resolution_clock::now()-begin).count();
    cout<<"result="<<tmp<<endl;
    cout<<"time used="<<dur<<" ms"<<endl;
    return 0;
}