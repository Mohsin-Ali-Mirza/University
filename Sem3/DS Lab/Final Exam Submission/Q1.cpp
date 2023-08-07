#include <iostream>
using namespace std;

class Node
{
public:
	int petrol;
	int dis;
	Node* next;

	Node(int petrol,int dis)
	{
		this->petrol = petrol;
		this->dis = dis;
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



	void insertAtEnd(int p,int d)
	{
		Node* new_Node = new Node(p,d);
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
		count++;
	}

	void traverse()
	{
		Node* curr = tail->next;

		do
		{
			cout << curr->petrol << "->";
			curr = curr->next;
		} while (curr != tail->next);

		cout << "END\n";
	}

	int fun(Node* start)
	{
		Node* curr = start;
		static int i = 0;
		do
		{
			if (curr->petrol < curr->dis)
			{
				i++;
				return fun(curr->next);
			}
			else
			{
				curr->petrol -= curr->dis;
				curr->next->petrol += curr->petrol;
				curr = curr->next;
			}
		} while (curr != start);

		return i;
	}


};

int main()
{
	int n;
	cin >> n;
	csll l1;
	for (int i = 0; i < n; i++)
	{
		int p;
		int d;
		cin >> p;
		cin >> d;
		l1.insertAtEnd(p, d);
	}


	cout<<l1.fun(l1.tail->next);

	return 0;
}

