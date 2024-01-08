#Include<bits/stdc++.h>
using namespace std;

int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<map<int,int>>v(n); // vector of map to store every elements possible sequence
        int ans=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                
                int xi = 0;
                int xj = 0;

                long long diffx = 1LL*(nums[i]) - 1LL*(nums[j]); 
                int diff = (int)diffx;
                if(diffx>=INT_MAX or diffx<=INT_MIN) continue; 

                if(v[j].find(diff) != v[j].end())
                {
                    xi = v[i][diff];
                    xj = v[j][diff];
                    v[i][diff]=(xi+xj+1);
                    ans+=xj;
                }
                else
                {
                    v[i][diff]++;
                }
            }
    /*for(auto it : v[i])
            {
                cout<<it.first<<" "<<it.second<<" ";
            }
            cout<<endl;*/
        }

        return ans;
    }
int main()
{
  int n;
  cin>>n;
  vector<int>v;
  for(int i=0;i<n;i++)
  {
      int x;
      cin>>x;
      v.push_back(x);
  }
  int ans = numberOfArithmeticSlices(v);
  cout<<ans;
}
