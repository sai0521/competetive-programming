#include <bits/stdc++.h>
using namespace std;
long long dp[1000001];
long long helper(int *arr,int n,int k)
{
  if(k==0) return 0;
  if(k<0) return 1e9;
  if(dp[k]!=-1) return dp[k];
  long long x=INT_MAX;
  for(int j=0;j<n;j++)
  {
    x = min(x,1+helper(arr,n,k-arr[j]));
  }
  return dp[k]=x;
}
int main() {
    long long n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    long long ans = helper(arr,n,m);
    if(ans > m) cout<<-1<<endl;
    else cout<<ans<<endl;
}
