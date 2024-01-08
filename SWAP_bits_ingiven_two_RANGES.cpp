#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int x=a;
    int y=b;
    int ans=0;
    for(int i=a;i<a+c;i++)
    {
        if((1<<i)&n) ans+=(pow(2,y));
        y++;
    }
    for(int i=b;i<b+c;i++)
    {
        if((1<<i)&n) ans+=(pow(2,x));
        x++;
    }
    for(int i=0;i<32;i++)
    {
        if((i>=a and i<a+c) or (i>=b and i<b+c)) continue;
        if((1<<i)&n) ans+=(pow(2,i));
    }
    cout<<ans;
}
