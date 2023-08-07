#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* prev;
	Node* next;

	Node(int data)
	{
		this->data = data;
		prev = NULL;
		next = NULL;
	}
};

class cdll
{
public:
	Node* head;
	Node* tail;
	int count = 0;
	cdll()
	{
		head = NULL;
		tail = NULL;
	}

	void insertAtEnd(int d)
	{
		count++;
		Node* new_Node = new Node(d);
		if (tail == NULL)
		{
			tail = new_Node;
			head = new_Node;
			new_Node->next = head;
		}
		else
		{

			new_Node->prev = tail;
			tail->next = new_Node;
			tail = new_Node;
		}
	}


	void removeDup()
	{
		Node* curr1 = head;
		while (curr1 != tail && curr1->next != tail)
		{
			Node* curr2 = curr1;

			while (curr2->next != tail)
			{
				if (curr1->data == curr2->next->data)
				{
					Node* dup = curr2->next;
					curr2->next = curr2->next->next;
					delete dup;
					count--;
				}
				else
				{
					curr2 = curr2->next;
				}
			}
			curr1 = curr1->next;
		}
		count--;
		cout << count<<"\n";

	}

	void traverse()
	{
		Node* curr = head;
		while (curr != tail)
		{
			cout << curr->data << "->";
			curr = curr->next;
		}
		cout <<"REPEAT"<<"\n";
	}
};





int main()
{
	cdll l1;
	int n;
	int num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		l1.insertAtEnd(num);
	}

	l1.removeDup();
	l1.traverse();
	

	return 0;
}

