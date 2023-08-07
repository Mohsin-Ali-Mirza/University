#include <iostream>
using namespace std;

void MinMax(int *arr, int &min,int &max)
{
	int temp;
	
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	max = arr[4];
	min = arr[0];
	
	delete []arr;
	arr = 0;
	
}

//void MinMax2(int *arr, int &min, int &max)
//{
//	min = arr[0];
//	max = arr[0];
//	
//	for(int i=1;i<5;i++)
//	{
//		if(arr[i]>max)
//		max = arr[i];
//		if(arr[i]<min)
//		min = arr[i];		
//	}
//	
//	delete []arr;
//	arr=0;
//}


int main()
{
	int min=0;
	int max=0;
	int *arr{new int[5]{8,3,6,4,1}};
	
	MinMax(arr,min,max);
	
	cout<<"Max:"<<max;
	cout<<"\nMin:"<<min;
	
return 0;
}

