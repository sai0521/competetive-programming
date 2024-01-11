#include<bits/stdc++.h>
using namespace std;
int mod = 7;
//// ONLY  FOR MODULAR ARTHEMATIC 
int power(int n,int k){//  BINARY EXPONENTION the optimal way to find powers of largest numbers
    int a=1;
    while(k)
    {
        if(k&1)
        {
            k=k-1;
            a*=n;
        }
        else
        {
            k/=2;
            n*=n;
        }
    }
    return a%mod;
}


int inverse(int b) // finds 1/b where  1<= b <=10^18
{
    return power(b,mod-2)%mod;
}


int main()
{
    int n = 2;
    cout<<(10*inverse(20))%mod;

}
