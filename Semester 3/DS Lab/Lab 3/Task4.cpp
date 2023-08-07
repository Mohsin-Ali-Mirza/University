#include <iostream>
using namespace std;


int main()
{
	bool arr[5][5] =	{ {0,1,0,1,1},
						  {1,0,1,0,1},
						  {0,1,0,0,0},
						  {1,0,0,0,1},
						  {1,1,0,1,0}
						};
	int p1;
	int p2;
	int pos;
	
	cout<<"Enter Person 1:";
	cin>>p1;
	cout<<"Enter Person 2:";
	cin>>p2;
	bool check = false;
	
	for(int j=0;j<5;j++)
	{
		if (arr[p1][j]==1 && arr[p2][j]==1)
		{
			check = true;
			cout<<"Friends with "<<j<<endl;
		}	
	}
	
	if(!check)
	cout<<"No Friends";
	
	
	return 0;
}
