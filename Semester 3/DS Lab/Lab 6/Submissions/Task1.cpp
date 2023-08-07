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

	void reverseTraverse()
	{
		Node* curr = tail;
		if (tail == NULL)
		{
			return;
		}
		else
		{
			while (curr != NULL)
			{
				cout << curr->data << "->";
				curr = curr->prev;
			}
			cout << "NULL\n";
		}
	}

	void insertAtFront(int d)
	{
		count++;
		Node* curr = head;
		Node* new_Node = new Node(d);
		if (head == NULL || tail == NULL)
		{
			head = new_Node;
			tail = new_Node;
		}
		else
		{
			new_Node->next = head;
			head->prev = new_Node;
			head = new_Node;
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

	void insertAtPosition(int d, int p)
	{
		Node* new_Node = new Node(d);
		Node* curr = head;
		if (p == 0)
		{
			insertAtFront(d);
		}
		else if (p == count)
		{
			insertAtEnd(d);
		}
		else
		{
			for (int i = 0; i < p; i++)
			{
				if (i == p - 1)
				{
					curr->next->prev = new_Node;
					new_Node->next = curr->next;
					curr->next = new_Node;
					new_Node->prev = curr;
				}
				curr = curr->next;
			}
			count++;
		}
	}

	void deleteFirst()
	{
		Node* temp = head;
		count--;
		if (head == NULL)
			return;
		else
		{
			head = head->next;
			head->prev = NULL;
			delete temp;
		}
	}

	void deleteEnd()
	{
		Node* temp = tail;
		count--;
		if (tail == NULL)
			return;
		else
		{
			tail = tail->prev;
			tail->next = NULL;
			delete temp;
		}
	}

	void deletePoisiton(int p)
	{
		Node* curr = head;
		Node* temp = head;
		if (p == 0)
		{
			deleteFirst();
		}
		else if (p == count - 1)
		{
			deleteEnd();
		}
		else
		{
			for (int i = 0; i < p; i++)
			{
				if (i == p - 1)
				{
					temp = curr->next;
					curr->next->next->prev = curr;
					curr->next = curr->next->next;
					delete temp;
					break;
				}
				curr = curr->next;
			}
			count--;
		}

	}

	int maximum()
	{
		Node* curr = head;
		int max = curr->data;
		while (curr != NULL)
		{
			if (max < curr->data)
				max = curr->data;
			curr = curr->next;
		}

		return max;

	}

	float mean()
	{
		float f = 0;
		Node* curr = head;
		while (curr != NULL)
		{
			f += curr->data;
			curr = curr->next;
		}
		f /= count;
		return f;
	}

	void sort()
	{
		Node* curr = head;
		for (int i = 0; i < count - 1; i++)
		{
			for (int j = 0; j < count - 1 - i; j++)
			{
				if (curr->data > curr->next->data)
					swap(curr->data, curr->next->data);
				curr = curr->next;
			}
			curr = head;
		}
	}

	void reverseLL()
	{
		Node* curr = head;
		Node* temp = head;
		while (curr != NULL)
		{
			temp = curr->prev;
			curr->prev = curr->next;
			curr->next = temp;
			curr = curr->prev;
		}

		if (temp != NULL)
		{
			head = temp->prev;
		}
	}
};

int main()
{
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

	return 0;
}
