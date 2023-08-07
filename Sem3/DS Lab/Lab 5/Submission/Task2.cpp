#include <iostream>
using namespace std;

int count=0;
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
	
	void insertAtFront(int d)
	{
		Node *new_Node = new Node(d);
		Node *curr = head;
		if(head == NULL)
			head = new_Node;
		else
		{
		new_Node->next = curr->next;
		curr->next = new_Node;
		}
		count++;
	}
	
	void insertAtEnd(int d)
	{
		Node *new_Node = new Node(d);
		Node *curr = head;
		if(head == NULL)
			head = new_Node;
		else
		{
			while(curr->next !=NULL)
			curr = curr->next;
			
			new_Node->next = curr->next;
			curr->next = new_Node;
		}
		count++;
	}
	
	void insertAtPosition(int p, int d)
	{
		Node *new_Node = new Node(d);
		Node *curr = head;
		if(head==NULL || p==0) 
			head == new_Node;
		else
		{
			for(int i=0;i<=p;i++)
			{
				if(i==p-1)
				{
					new_Node->next = curr->next;
					curr->next = new_Node;
				}
				curr = curr->next;
			}
		}
		count++;
	}
	
	void deleteFirst()
	{
		Node *temp = new Node(0);
		if(head==NULL)
		return;
		else
		{
			temp = head;
			head = head->next;
		}
		delete temp;
		count--;
	}
	
	void deleteEnd()
	{
		Node *temp = new Node(0);
		Node *curr = head;
		if(head==NULL)
		return;
		else
		{
			while(curr->next->next!=NULL)
			{
				curr = curr->next;
			}
			
			temp = curr->next;
			curr->next = NULL;
			delete temp;
		}
		count--;
	}
	
	void deletePosition(int p)
	{
		Node *temp = new Node(0);
		Node *curr = head;
		if(head==NULL)
		return;
		else
		{
			for(int i=0;i<=p;i++)
			{
				if(i==p-1)
				{
					temp = curr->next; 
					curr->next = curr->next->next;
				}
				curr = curr->next;
			}
			delete temp;
		}
		count--;
	}
	
	int maximum()
	{
		Node *curr = head;
		int max = curr->data;
		while(curr!=NULL)
		{
			if(max<curr->data)
				max = curr->data;
			curr = curr->next;
		}
		return max;
	}
	
	float mean()
	{
		Node *curr = head;
		float m;
		while(curr!=NULL)
		{
			m += curr->data;
			curr=curr->next;
		}
		m/=count;
		return m;
	}
	
	void sort()
	{
		Node *curr = head;
		for(int i=0;i<count-1;i++)
		{
			for(int j=0;j<count-1-i;j++)
			{
				if(curr->data > curr->next->data)
					swap(curr->data,curr->next->data);
				curr = curr->next;
			}
			curr = head;
		}
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
	
	void reversell()
	{
		Node *next_node = NULL;
		Node *curr = head;
		Node *prev = NULL;
		while(curr->next != NULL)
		{
			next_node = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next_node;
		}
		curr->next = prev;
		head = curr;
	}
};

int main()
{
	sll l1;
	l1.insertAtFront(1);
	l1.insertAtEnd(2);
	l1.insertAtEnd(3);
	l1.insertAtPosition(2,4);
	cout<<"Before Deletion"<<endl;
	l1.traverse();
	cout<<"After Deletion"<<endl;
	//l1.deleteEnd();
	l1.deletePosition(1);
	l1.traverse();
	cout<<"Maximum value Of The list is:"<<l1.maximum()<<endl;
	cout<<"Mean value Of The list is:"<<l1.mean()<<endl;
	l1.reversell();
	cout<<"After Reverse"<<endl;
	l1.traverse();
	cout<<"After Sorted:"<<endl;
	l1.sort();
	l1.traverse();
	
	
	return 0;
}
