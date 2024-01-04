#include<bits/stdc++.h>
using namespace std;

int nearest_2pow(int x)// returns the previous 2 powers bit count
{
	int c=0;
	while((1<<c)<=x)
	{
		c++;
	}
	return c-1;
}
int count_setbits(int n)
{
	if(n==0) return 0;
	int x = nearest_2pow(n);

	int a = x*(1<<x-1) + 1 // gives the total numbers of set bits of prev 2 power (and) +1 for power bit 
	int b = n-(1<<x)  // gives msb 1's in remaining numbers greater than prev 2 poer and lessthan given n
	int c = count_setbits(n-(1<<x)) // recursively call remaining bits excludiing msb bits

	int ans= a + b + c;

	return ans;
}
int main()
{
	int n;
	cin>>n;
	cout<<count_setbits(n);
}

/*

for input 13 prev 2 power is 8
------------
0 	0 0 0 0 |
1 	0 0 0 1 |
2 	0 0 1 0 |
3 	0 0 1 1 |-----  x * (1<<x-1)   gives total numbers of 1's from 0 to 2 power-1
4 	0 1 0 0 |
5 	0 1 0 1 |
6 	0 1 1 0 |
7 	0 1 1 1 |
-----------
8 	1 0 0 0 |---------   1
-----------
9 	|1| |0 0 1 |
10  |1| |0 1 0 |
11  |1| |0 1 1 |----------  recursion call to count set bits
12 	|1| |1 0 0 |
13  |1| |1 0 1 |
     |
     |
     |
     |-----------  n-(1<<x)  gives the remaining msb ones
*/