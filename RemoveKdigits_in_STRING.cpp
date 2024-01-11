#include<bits/stdc++.h>
using namespace std;
string removeKdigits(string S, int K) {
        
        string ans="";
        int n=S.size();
        int i=0;
        while(i<n)
        {
            while(K and !ans.empty() and ans.back()>S[i])
            {
                ans.pop_back();
                K--;
            }
            ans+=S[i];
            i++;
        }
        while(K and !ans.empty())
        {
            ans.pop_back();
            K--;
        }
        
      i=0;
      while(ans[i]=='0' and i<n)
      {
          i++;
      }
      
      if(i==ans.size()) return "0";

        return ans.substr(i);
    }
int main()
{
  string s;
  cin>>s;
  int k;
  cin>>k;
  string ans = removeKdigits(s,k);
  cout<<ans;
}
