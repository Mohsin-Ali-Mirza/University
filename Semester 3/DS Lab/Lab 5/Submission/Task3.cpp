#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		float data;
		Node *next;
		
		Node(float data)	
		{
			this->data = data;
			next = NULL;
		}
};

class sll
{
	Node *head;
	public:
	sll()
	{
		head = NULL;	
	}
	
	void insertAtEnd(float d)
	{
		Node *curr = head;
		Node *new_Node = new Node(d);
		
		if(head==NULL)
		{
			head = new_Node;
			return;
		}
		
		while(curr->next!=NULL)
		curr = curr->next;
		
		curr->next = new_Node;	
	}	
	
	void traverse()
	{
		Node *curr = head;
		while(curr!=NULL)
		{
			cout<<curr->data<<endl;
			curr = curr->next;
		}
	}
	
	
	void specialAverage(sll numList)
	{
		int n = 12;
		Node *curr = numList.head;
		int size = n-4+1;
		int count[size]={0};
		float sum[size]={0};
		int i=0;
		while(curr!=NULL)
		{
			for(int j=0;j<size;j++)
			{
				if(j<=i)
				{
					if(count[j]<4)
					{
						sum[j]+=curr->data;
						count[j]++;
					}
				}
				else
				break;
			}
			curr = curr->next;
			i++;
		}
		
	
		curr = this->head;
		for(int j=0;j<size;j++)
		{
			curr->data = sum[j]/4;
			cout<<curr->data<<"\n";
			curr = curr->next;
		}
	}
};


int main()
{
	int num[12];
	int n = sizeof(num)/sizeof(int);
	sll numList;
	for(int i=0;i<n;i++)
	cin>>num[i];
	
	for(int i=0;i<n;i++)
		numList.insertAtEnd(num[i]);
		sll avg;
		for(int i=0;i<12;i++)
		avg.insertAtEnd(0);	
		avg.specialAverage(numList);
	//	avg.traverse();
		
	
		//1 2 3 4 5 6 7 8 9 10 11 12
		



return 0;
}

