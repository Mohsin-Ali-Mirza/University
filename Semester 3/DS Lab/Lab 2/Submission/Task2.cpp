#include <iostream>
using namespace std;

void fun(int *arr, int n,int min, int max)
{
		while(min<=max){
		for(int i=0;i<10;i++){
			if(min==arr[i]){
				cout<<arr[i]<<"\n";
			}
	    }
	    min++;
	}
}

int main()
{
	//int arr[10]={9,9,3,5,1,2,2,1,2,4};
	int arr[10]={9,9,9,9,9,9,9,9,9,9};
	int n=10;
	int min=arr[0],max=arr[0];
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]<min)
		min = arr[i];
		
		if(arr[i]>max)
		max = arr[i];
	}
	

	fun(arr,n,min,max);
	
	return 0;
}
