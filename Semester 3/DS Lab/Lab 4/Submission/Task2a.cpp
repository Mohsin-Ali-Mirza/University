#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void fun2(int i,int n);

void fun1(int i, int n)
{
	if(n==0)
		return;
	
	fun2(i,n);
}

void fun2(int i,int n)
{
	static int j=1;
	j++;
	cout<<i<<"\n";
	fun1(i+j,n-1);
}

int main()
{
	fun1(1,7);
	


return 0;
}

