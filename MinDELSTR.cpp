#include<bits/stdc++.h>
using namespace std;
int minDeletions(string s) {
        
        //APPROACH - 1
        /*vector<int>v(26,0);
        for(int i=0;i<s.size();i++)
        {
            v[s[i]-'a']++;
        }
        int res=0;
        unordered_set<int>us;
        for(int i=0;i<26;i++)
        {
            while(v[i]>0 && us.find(v[i])!=us.end())
            {
                res+=1;
                v[i]-=1;
            }
            us.insert(v[i]);
        }
        return res;*/

        //APPROACH - 2
        int freq[26]={0};

        for(int i=0;i<s.size();i++)
        {
            freq[s[i]-'a']++;
        }

        int res=0;

        sort(begin(freq),end(freq));

        for(int i=24 ; i>=0 && freq[i]>0 ;i--)
        {
            if(freq[i] >= freq[i+1])
            {
                int x = freq[i];
                freq[i]=max(0,freq[i+1]-1);
                res+= x-freq[i];
            }
        }
        return res;
        
}
int main()
{
    string s;
    cin>>s;
    cout<<minDeletions(s);
}

