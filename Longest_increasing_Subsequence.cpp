#include<bits/stdc++.h>
using namespace std;
int lengthOfLIS(vector<int>& nums)
{
        vector<int>v;
        v.push_back(nums[0]);

        function<void(int)> helper = [&](int x)
        {
            int l=0,h=v.size()-1;
            while(l<h)
            {
                int m = (l+h)/2;
                if(x<=v[m]) h=m;
                else l=m+1;
            }
            if(l<nums.size() and v[l]<x) l++;

            if(l>=v.size()) v.push_back(x);
            else v[l]=x;
        };

        for(int i=1;i<nums.size();i++)
        {
            helper(nums[i]);
        }

        for(auto it:v)
        {
            cout<<it<<" ";
        }
        cout<<endl;

        return v.size();

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
    int s = lengthOfLIS(v);
    cout<<"longest size is "<<s;
}

