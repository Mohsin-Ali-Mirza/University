#include <iostream>
using namespace std;

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

class sll
{
	Node* head;
public:
	int count = 0;
	sll()
	{
		head = NULL;
	}

	void insertAtEnd(int d)
	{
		Node* new_Node = new Node(d);
		Node* curr = head;
		if (head == NULL)
			head = new_Node;
		else
		{
			while (curr->next != NULL)
				curr = curr->next;

			new_Node->next = curr->next;
			curr->next = new_Node;
		}
		count++;
	}

	void traverse()
	{
		Node* curr = head;
		while (curr != NULL)
		{
			cout << curr->data << "->";
			curr = curr->next;
		}
		cout << "NULL\n";
	}

	void removeDup()
	{
		Node* curr1 = head;
		while (curr1 != NULL && curr1->next != NULL)
		{
			Node* curr2 = curr1;
			
			while (curr2->next != NULL)
			{
				if (curr1->data == curr2->next->data)
				{
					Node* dup = curr2->next;
					curr2->next = curr2->next->next;
					delete dup;
				}
				else
				{
					curr2 = curr2->next;
				}
			}
			curr1 = curr1->next;
		}

	}
};

int main()
{
	int n;
	cin >> n;
	sll d1;
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		d1.insertAtEnd(num);
	}
	d1.removeDup();
	d1.traverse();

	//12 11 12 21 41 43 21
	return 0;
}
