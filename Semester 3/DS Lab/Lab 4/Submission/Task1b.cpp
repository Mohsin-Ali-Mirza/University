#include <iostream>
#include<bits/stdc++.h>
using namespace std;


void fun(int i, int n)
{
	static int j=-1;
	j++;
	if(n==0)
		return;
	cout<<i<<"\n";
	fun(i+j,n-1);
}

int main()
{
	fun(1,8);
	


return 0;
}

