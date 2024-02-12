#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n,m;
    cin>>n>>m;
    long long arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    vector<long long>v(m+1,0);
    for(int i=1;i<=m;i++)
    {
      long long mn=INT_MAX;
      for(int j=0;j<n;j++)
      {
        long long x = i-arr[j];
        if(x < 0 ) continue;
        //cout<<x<<" ";
        mn=min(mn,v[x]);
      }

      v[i]=mn+1;
      //cout<<v[i]<<" ";
    }
    if(v[m]<=m) cout<<v[m]<<endl;
    else cout<<-1<<endl;

}
