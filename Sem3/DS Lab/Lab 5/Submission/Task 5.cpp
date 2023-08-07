#include <iostream>
using namespace std;


bool fib(int val);

class Node
{
	public:
	int data;
	Node* next;
	
	
		Node()
		{
			
			next=NULL;
		}
		
		
};

class sll
{
	private:
		Node* head;
	
	public:
		sll()
		{
		}
				
		void traverse()
		{
			Node* curr=head;
			
			while(curr!=NULL)
			{
				cout<<curr->data<<" ";
				curr=curr->next;
			}
			cout<<"\n";
			
		}


		void insertAtEnd(int element)
		{
			Node* curr=head;
			Node* newnode=new Node();
			
			if(head==NULL)
			{
				newnode->data=element;
				head=newnode;
				return;
			}
			
			while(curr->next!=NULL)
			{
				curr=curr->next;
			}
			
			curr->next=newnode;
			newnode->data=element;
			
		}

		
		void reverse()
		{
			Node *curr=head;
			Node *prev=NULL;
			Node *next=NULL;
			
			while(curr!=NULL)
			{
				next=curr->next;
				curr->next=prev;
				prev=curr;
				curr=next;
			}
			head=prev;
		}
		
		void odd()
		{
			double mean;
			int count=0;
			
			Node* curr=head;
			
			while(curr!=NULL)
			{
				if(curr->data%2!=0 && fib(curr->data))
				{
					count++;
					mean=mean+curr->data;
				}
				curr=curr->next;
			}
			
			cout<<mean/count;
			
		}
};


bool fib(int val)
{
	int n=20;
	int arr[n];
	int i=0;
	while(i<n)
	{
		if(i==0||i==1)
		arr[i]=1;
		else
		arr[i]=arr[i-2]+arr[i-1];
		i++;	
	}
	
	int j=0;
	while(j<n)
	{
		if(arr[j]==val)
			return true;
		j++; 
	}
	
	return false;
}


int main()
{
	int n,num;
	cin>>n;
	sll l1;
	
	for(int i=0;i<n;i++)
	{
		cin>>num;
		l1.insertAtEnd(num);
	}
	
	cout<<"Mean: ";
	l1.odd();
	
}

