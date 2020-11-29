/*
ID: harrych3
TASK: ride
LANG: C++
*/
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	//decomment following lines when submit
	//freopen("ride.in","r",stdin);
	//freopen("ride.out","w",stdout);
	string comet;
	string name;
	cin>>comet>>name;
	long long a=1;
	for(int i=0;i<comet.size();i++){
		a*=(comet[i]-'A'+1)%47;
		a%=47;
	}
	long long b=1;
	for(int i=0;i<name.size();i++){
		b*=(name[i]-'A'+1)%47;
		b%=47;
	}
	if(a==b){
		cout<<"GO"<<endl;
	} else{
		cout<<"STAY"<<endl;
	}
	return 0;
}
