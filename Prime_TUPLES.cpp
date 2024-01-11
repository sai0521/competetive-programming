#include <bits/stdc++.h>
using namespace std;
vector<int>v(1e6+2,1);
vector<int>primes;
void sieve()
{
    v[0]=0;
    v[1]=1;
    int i=2;
    while(i*i<1e6+2)
    {
        if(v[i]==1)
        {
            primes.push_back(v[i]);
            for(int j=i*i;j<1e6+2;j+=j)
            {
                v[j]=0;
            }
        }
        i+=1;
    }
}
int main() {
	// your code goes here
    int x;
    cin>>x;
    sieve();
    while(x--)
    {
        int ans=0;
        int n;
        cin>>n;
        for(int i=3;i<=n;i+=2)
        {
            if(v[i]==1 and i+2<=n and v[i+2]==1)
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}

/*


A tuple (a,b,c) is considered good if it consists of three prime numbers a, b and c such that a<b<c≤N and a+b=c.
Two tuples are considered different if they differ in at least one position. Given N, find the number of good tuples that can be formed by integers from 11 to N.
Input
•	The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
•	The following T lines contain a single integer N.
Output
For each test case, print a single line containing one integer — the number of good tuples which can be formed using integers from 1 to N.
Constraints
•	1≤T≤10^5
•	1≤N≤10^6

Input:
2
3
6

Output:
0
1


*/
