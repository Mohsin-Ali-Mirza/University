#include <iostream>
using namespace std;

class Node
{

public:
	int data;
	Node* next;
	Node* prev;

	Node(int data)
	{
		this->data = data;
		next = NULL;
		prev = NULL;
	}
};

class dll
{
	Node* head;
	Node* tail;

public:
	int count;
	dll()
	{
		head = NULL;
		tail = NULL;
		count = 0;
	}


	void traverse()
	{
		Node* curr = head;
		if (head == NULL)
		{
			return;
		}
		else
		{
			while (curr != NULL)
			{
				cout << curr->data << "->";
				curr = curr->next;
			}
			cout << "NULL\n";
		}
	}

	void insertAtEnd(int d)
	{
		count++;
		Node* curr = tail;
		Node* new_Node = new Node(d);
		if (tail == NULL || head == NULL)
		{
			tail = new_Node;
			head = new_Node;
		}
		else
		{
			new_Node->prev = tail;
			tail->next = new_Node;
			tail = new_Node;
		}
	}

	void fun()
	{
		Node* curr = head;
		if (count % 2 != 0)
		{
			for (int i = 0; i < count; i++)
			{
				if (i == count / 2)
				{
					cout << curr->data<<"\n";
					break;
				}
				curr = curr->next;
			}
		}
		else
		{
			for (int i = 0; i < count; i++)
			{
				if (i == count / 2)
				{
					cout << curr->data<<"\n";
					break;
				}
				curr = curr->next;
			}
		}
	}

	void implementation()
	{
		/*
		dll l1;
		l1.insertAtFront(3);
		l1.insertAtFront(2);
		l1.insertAtFront(1);
		l1.insertAtEnd(4);
		l1.insertAtEnd(5);
		l1.insertAtPosition(6, 5);

		cout << "Before Deletion At First:";
		l1.traverse();
		cout << "After Deletion At First:";
		l1.deleteFirst();
		l1.traverse();


		cout << "After Deletion At End: ";
		l1.deleteEnd();
		l1.traverse();
		cout << "After Deletion At Position 2: ";
		l1.deletePoisiton(2);
		l1.traverse();


		cout << "Maximum Of The Linked List is:" << l1.maximum();

		cout << "\nMean Of The Linked List is:" << l1.mean();

		l1.insertAtPosition(8, 1);
		cout << "\nBefore Sort :";
		l1.traverse();
		cout << "After Sort :";
		l1.sort();
		l1.traverse();


		cout << "After Reversing List:";
		l1.reverseLL();
		l1.traverse();
		*/
	}
};

int main()
{
	dll d1;
	d1.insertAtEnd(1);
	d1.insertAtEnd(2);
	d1.insertAtEnd(3);
	d1.insertAtEnd(4);
	d1.insertAtEnd(5);
	d1.fun();

	dll d2;
	d2.insertAtEnd(1);
	d2.insertAtEnd(2);
	d2.insertAtEnd(3);
	d2.insertAtEnd(4);
	d2.insertAtEnd(5);
	d2.insertAtEnd(6);
	d2.fun();




	return 0;
}
