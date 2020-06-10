/*
ID: harrych3
TASK: beads
LANG: C++
*/
#include<iostream>
using namespace std;
char beads[400];
int ans=0;
int main()
{
    //decomment following lines when submit
    //freopen("beads.in","r",stdin);
    //freopen("beads.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>beads[i];
    }
    for(int i=0;i<n;i++){
        char c=beads[i];
        int cnt=0;
        for(int j=i;j<i+n;j++){
            if(beads[j%n]==c||beads[j%n]=='w'){
                cnt++;
            } else{
                break;
            }
        }
        c=beads[i-1];
        int rcnt=0;
        for(int j=i-1;(j>=0&&j<i)||(j<0&&j%n>=i);j--){
            if(beads[j%n]==c||beads[j%n]=='w'){
                rcnt++;
            } else{
                break;
            }
        }
            ans=max(ans,cnt+rcnt);
    }
    cout<<min(n,ans)<<endl;
    return 0;
}