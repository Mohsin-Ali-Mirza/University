#include <iostream>
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

class Linkedlist
{
	Node *head;
	public:
		Linkedlist()
		{
			this->head = NULL;
		}
		Linkedlist BuildOneTwoThree()
		{
			Node* second = new Node(2);
			Node* third = new Node(2);
			Node* fourth = new Node(2);
			head= second;
			head->next = third;
			head->next->next = fourth;
			Linkedlist temp;
			temp.head = head;
			return temp;	
		}	
		
		void CountTest()
		{
			Linkedlist myList = BuildOneTwoThree();
			int count = Count(myList.head,2);
			cout<<count;
		}
		
		int Count(Node *llist, int searchFor)
		{
			int c=0;
			Node* curr = new Node(0);
			curr = llist;
			while(curr !=NULL)
			{
				if(curr->data == searchFor)
					c++;
				curr = curr->next;
			}
			return c;
		}
};

int main()
{
	Linkedlist list1;
	list1.CountTest();
	
	
	
	return 0;
}
