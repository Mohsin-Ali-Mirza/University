#include <iostream>
using namespace std;

int main()
{
	int num,sum;
	while(1)
	{
		cout<<"Enter Your Number:";
		cin>>num;
		
		if(num<0)
		exit(1);
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
			cout<<"Sum:"<<sum<<"\n";
		}
		
	}
	
	return 0;
}
