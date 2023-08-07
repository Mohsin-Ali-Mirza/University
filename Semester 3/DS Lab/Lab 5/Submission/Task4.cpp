#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
		
		Node(int data)
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
		void insertAtEnd(int d)
		{
			Node *curr = head;
			Node *new_Node = new Node(d);
			
			if(head==NULL)
			{
				head = new_Node;
				return;
			}
			
			while(curr->next!=NULL)
			{
				curr = curr->next;
			}			
			curr->next = new_Node;
			
		}
		
		sll& operator=(const sll& obj){
			if (this != &obj){
				deleteList();
				Node *temp_node = obj.head;	// to iterate through obj's list
				Node *last_node, *n;
				
				while(temp_node!=NULL){
					n = new Node(temp_node->data);
					
					if (head == NULL){
						head = n;
					}
					else{
						last_node->next = n;
					}
					last_node = n;
					temp_node = temp_node->next;
				}
			}
			return *this;
		}
		
		void deleteList(){
			if (head != NULL){
				Node *temp;		
				Node *curr = head; // to iterate
				
				while(curr != NULL){
					temp = curr; // hold curr to delete later on
					curr = curr->next;
					delete temp;
				}
			}
		}
		
		void reversell()
		{
			Node *curr = this->head;
			Node *prev = NULL;
			Node *next_Node = NULL;
			
			while(curr->next!=NULL)
			{
				next_Node = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next_Node;
			}
			curr->next = prev;
			this->head = curr;
			
			prev = NULL; 
		}
		
		void traverse()
		{
			Node *curr = head;
			while(curr!=NULL)
			{
				cout<<curr->data<<"->";
				curr = curr->next;
			}
			cout<<"NULL\n";
		}
		
		void fun(sll original,sll reverse, int n)
		{
			Node *curr = original.head;
			bool anyOneOdd = false;
			bool anyOneEven = false;
			while(curr!=NULL)
			{
				if(curr->data % 2 != 0)
				{
					anyOneOdd = true;
				}
				else
					anyOneEven = true;
					
				curr = curr->next;
			}
			
			if(anyOneOdd && anyOneEven)
			{
				curr = original.head;
				Node *curr2 = reverse.head;
				int i=0;
				int pos=n;
				int val;
				while(curr!=NULL)
				{
					if(curr->data % 2 != 0 && curr2->data % 2 == 0)
					{
						val = curr->data;
						swap(curr->data,curr2->data);
						pos -= i;
						break;
					}
					curr = curr->next;
					curr2 = curr2->next;
					i++;
				}
				
				curr = original.head;
				curr2 = reverse.head;
				i=1;
				while(curr!=NULL)
				{
					if(pos==i)
					{
						swap(curr->data,val);
						return;
					}
					curr2= curr2->next;
					curr = curr->next;
					i++;
				}
			}
		}
		
};


int main()
{
	int test;
	int test1[4]={2,6,8,2};
	int test2[5]={4,3,5,2,3};
	int n;
	int size;
	sll original;
	
	cin>>test;
	if(test==1)
	{
		int n=4;
		for(int i=0;i<n;i++)
			original.insertAtEnd(test1[i]);	
	}
	else
	{
		int n= 5;
		for(int i=0;i<n;i++)
			original.insertAtEnd(test2[i]);	
	}
	
	sll reverse = original;
	sll result;
	
	cout<<"Input:";
	original.traverse();
	reverse.reversell();
	
	if(test==1)
	{
		int n=4;
		size = n;
		for(int i=1;i<n;i++)
			original.insertAtEnd(test1[i]);	
	}
	else
	{
		int n= 5;
		size = n;
		for(int i=1;i<n;i++)
			original.insertAtEnd(test2[i]);	
	}
	
//	original.traverse();
	original.fun(original,reverse,size);
	cout<<"\nOutput:";
	original.traverse();
	
	

	



return 0;
}

