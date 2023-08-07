#include <iostream>
using namespace std;

void display(int *arr,int n)
{
	for(int k=0;k<n;k++)
	{
		cout<<arr[k]<<endl;
	}
}

int main()
{
	int n=9;
	int arr[n]={9,3,9,5,1,2,2,1,2};
	int temp;

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(i%2==0)
			{
				if(arr[j]>arr[i])
					swap(arr[j],arr[i]);
			}
			
			
			else
				if(arr[j]<arr[i])
					swap(arr[j],arr[i]);		
		}
	}
	
	display(arr,n);

}
