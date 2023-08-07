#include <iostream>
using namespace std;

class Node
{
public:
	string data;
	Node* next;
	string msg;

	Node(string data)
	{
		this->data = data;
		next = NULL;
	}
};

class csll
{

public:
	Node* tail;
	int count;
	csll()
	{
		tail = NULL;
	}

	void insertAtEnd(string d)
	{
		count++;
		Node* new_Node = new Node(d);
		if (tail == NULL)
		{
			tail = new_Node;
			new_Node->next = tail;
		}
		else
		{
			new_Node->next = tail->next;
			tail->next = new_Node;
			tail = new_Node;
		}
	}

	void searchPos(int pos)
	{
		if (pos <= count)
		{
			Node* curr = tail->next;
			if (pos == 0)
			{
				cout << "Router\n";
			}
			else
			{
				for (int i = 0; i < pos; i++)
				{
					if (i == pos - 1)
					{
						cout << "Position:" << curr->data << "\n";
						return;
					}
					curr = curr->next;
				}
			}
		}
		cout << "Position Not Found!\n";

	}

	string getMsg(string s)
	{
		Node* curr2 = tail->next;
		while (curr2 != tail)
		{
			if (curr2->data == s)
			{
				cout << "Message Recieved:" << curr2->msg;
				break;
			}
			curr2 = curr2->next;
		}

		if (curr2->data != s)
		{
			return "Device Not Found!\n";
		}
		else
		{
			cout << "Message Recieved:" << curr2->msg;
		}
	}

	void setMsg(string s,string m)
	{
		Node* curr = tail->next;
		while (curr != tail)
		{
			if (curr->data == s)
			{
				curr->msg = m;
				return;
			}
			curr = curr->next;
		}

		if (curr->data == s)
			curr->msg = m;
		else
			cout << "Device Not Found!\n";
	}

	void communicate(string dest, string source)
	{
		Node* curr = tail->next;
		while (curr != tail)
		{
			if (curr->data == dest)
			{
				break;
			}
			curr = curr->next;
		}

		if (curr->data != dest)
		{
			cout << "Device Not Found!\n";
			return;
		}

		Node* curr2 = tail->next;
		while (curr2 != tail)
		{
			if (curr2->data == source)
			{
				break;
			}
			curr2 = curr2->next;
		}

		if (curr2->data != source)
		{
			cout << "Device Not Found!\n";
			return;
		}
		curr->msg = curr2->msg;
	}
};


int main()
{
	csll l1;
	l1.insertAtEnd("Device 1");
	l1.insertAtEnd("Device 2");
	l1.insertAtEnd("Device 3");
	l1.insertAtEnd("Device 4");
	l1.insertAtEnd("Device 5");
	l1.insertAtEnd("Device 6");

	l1.searchPos(3);
	l1.setMsg("Device 1", "Send Some Data To Printer");
	l1.communicate("Device 6", "Device 1");
	cout<<l1.getMsg("Device 6");


	return 0;
}
