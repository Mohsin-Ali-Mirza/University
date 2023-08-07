#include <iostream>
using namespace std;

int factor(int num)
{
	int sum;
	if(num<0)
	throw num;
	else
	{
		cout<<"Factors:"<<"\n";
		for(int i=1;i<=num;i++)
		{
			if(num%i==0)
			{
				cout<<i<<"\n";
				sum+=i;
			}
		}
		return sum;
	}
}

int main()
{
	int num;
	while(1)
	{
	cout<<"Enter Your Number:";
	cin>>num;
		try
		{
			cout<<"Sum:"<<factor(num)<<"\n";
		}
		catch(int a)
		{
			cout<<"Exception occured";
			exit(1);
		}
	}

	
	return 0;
}
