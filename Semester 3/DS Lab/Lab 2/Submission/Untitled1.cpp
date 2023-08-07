#include <iostream>
using namespace std;

class A
{
	
};

int main ()
{
	int n;
	int m;
	cout<<"Enter the Total Rows:";
	cin>>n;
	cout<<"Enter The Total Columns:";
	cin>>m;
	
	int ** arr = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i] = new int[m];
	}
		
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<"Enter Element "<<i<<j<<":";
			cin>>arr[i][j];
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i==j)
			{
				if(arr[i][j] == 1)
				{
					continue;
				}
			}
			else if(arr[i][j] == 0)
				{
					continue;
				}
				else 
				{
					cout<<"\nThis Array Is Not An Identity Matrix";
					exit(1);
				}
		}
	}
	
	cout<<"\nThis Array Is An Identity Matrix";
	
	return 0;
}