#include <iostream>
using namespace std;

const int max = 10;
class Node
{
public:
	int data;
	Node* next;

	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

class stack_sll
{
public:
	Node* top;
	int count=0;
	stack_sll()
	{
		top = NULL;
	}

	void insertAtFront(int d)
	{
		count++;
		Node* new_Node = new Node(d);
		if (top == NULL)
		{
			top = new_Node;
			cout << new_Node->data << " was Pushed In The Stack\n";
		}
		else if (max == count)
		{
			cout << "\nHeap Full\n";
			return;
		}
		else
		{
			new_Node->next = top;
			top = new_Node;
			cout << new_Node->data << " was Pushed In The Stack\n";
		}
	}

	void traverse(int x)
	{
		Node* curr = top;
		while (curr != NULL)
		{
			cout << curr->data << "->";
			curr = curr->next;
		}
		cout << "NULL\n";

		if(x)
		reversell();
	}

	void reversell()
	{
		Node* curr = top;
		Node* nextnode = NULL;
		Node* prev = NULL;

		while (curr->next != NULL)
		{
			nextnode = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextnode;
		}
		curr->next = prev;
		top = curr;

		traverse(0);
	}

	int pop()
	{
		
		if (top == NULL)
		{
			cout << "Stack is Empty\n";
			return 0;
		}

		else
		{
			Node* temp = top;
			top = top->next;
			return temp->data;
			delete temp;
		}
	}
};

int main()
{
	stack_sll s1;
	for (int i = 10; i > 1; i--)
	{
		s1.insertAtFront(i);
	}
	cout<<s1.pop()<<endl;

	s1.traverse(1);



	return 0;
}