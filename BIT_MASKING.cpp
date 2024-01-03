#include<bits/stdc++.h>
using namespace std;
void print_binary(int n)
{
	string s="";
	for(int i=32;i>=0;i--)
	{
		if(n & (1<<i)) s+="1";
		else s+="0";
	}
	cout<<s;
}
int main()
{
	int n;
	cin>>n;
	print_binary(n);
}