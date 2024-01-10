#include<bits/stdc++.h>
using namespace std;
int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    int s=0,res=0,x;
	    map<int,int>mpp;
	    mpp[0]=-1;
	    for(int i=0;i<n;i++)
	    {
	        s+=arr[i];
	        int rem=s%k;
	        if(rem<0)
	        {
	            rem+=k;
	        }
	        if(mpp.find(rem)!=mpp.end())
	        {
	            res=max(res,i-mpp[rem]);
	        }
	        else
	        {
	            mpp[rem]=i;
	        }
	    }
	    return res;
	}

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
     cin>>arr[i];
  }
  int k;
  cin>>k;
  int ans = longSubarrWthSumDivByK(arr,n,k);
  cout<<ans;
}
                                                          
/*  index  =  0   1   2   3   4   5                       map   /// these are first occurencecs of sum_mods in the  array
          [   2   7   6   1   4   5  ]                    | 0 : -1     
    sum = 0---2---9---15--16--20--25---                   | 2 : 0
sum_mod = 0   2   0   0   1   2   1                       | 1 : 3
              |               |
              ----------------  same mods so (2) that is we get extra 2 in index 4  from index 0 ...so, if we subtrack first occorence of sum_mod value then we get perfectly divisible value 
                                from that we can get the length
    
*/
