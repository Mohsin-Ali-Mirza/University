#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Animal
{
	string name;
	
	public:
	Animal()
	{
		
	}
	
	Animal(string name)
	{
		this->name = name;	
	}
	
	string getName() const
	{
		return name;	
	}
	
	void setName(string name)
	{
		this->name = name; 
	}		
};

int main()
{	
	Animal *an{new Animal[5]{Animal("Zebra"),Animal("Owl"),Animal("Crab"),Animal("Husky"),Animal("Cat")}};
	string arr[5];

	for(int i=0;i<5;i++)
	arr[i] = an[i].getName();

	sort(arr,arr+5);
	for(int i=0;i<5;i++)
	an[i].setName(arr[i]);
	

	for(int i=0;i<5;i++)
	cout<<an[i].getName()<<"\n";

return 0;
}

