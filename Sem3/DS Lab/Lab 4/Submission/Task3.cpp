#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void display(int *arr, int n);
void tailSortCol(int *arr, int n, int i);

void tailSortRow(int *arr, int n,int i)
{
	
	if(i==n)
	{
		cout<<"\nTail Sort\n";
		display(arr,n);
	}
	
	return tailSortCol(arr,n,i);
	
}

void tailSortCol(int *arr, int n, int i)
{
	static int j=0;
		if(j==n-1-i)
		{
			j=0;
			i++;
			return tailSortRow(arr,n,i);
		}
		if(arr[j+1]<arr[j])
			swap(arr[j],arr[j+1]);
		
		j++;
		return tailSortCol(arr,n,i);
}


void recursive(int *arr, int n)
{
	  if (n == 1)
	  {
	  	cout<<"\nRecursive Sort\n";
        return;
	  }
        
    for (int i=0; i<n-1; i++)
        if (arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
 

    recursive(arr, n-1);
}
 

void display(int *arr, int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}

int main()
{
	int n;
	cin>>n;
	int *arr = new int[n];
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	int a;
	cout<<"Enter 1 For Tail Sort Or 2 For Nomral Recursive Sort:";
	cin>>a;
	switch(a)
	{
		case 1:
			tailSortRow(arr,n,0);
			break;
		case 2:
			recursive(arr,n);
			display(arr,n);
			break;
		default:
			recursive(arr,n);
			break;
	};
				
	

return 0;
}

