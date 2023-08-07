#include<iostream>
using namespace std;

const int max = 2;

class Node
{
public:
	int data;
	Node* link;
};

class Queue
{
public:
	Node* front;
	Node* rear;
	int size=0;

	Queue()
	{
		front = NULL;
		rear = NULL;
	}

	void ADDMember(int value)
	{
		if (!QueueCapacity())
		{
			Node* temp = new Node;
			temp->data = value;
			if (front == NULL)
				front = temp;
			else
				rear->link = temp;

			rear = temp;
			rear->link = front;
			size++;
		}
		
	}

	bool QueueCapacity()
	{
		if (max == size)
		{
			cout << "Overflow\n";
			return true;
		}
		return false;
	}
	
	
	int RemoveMember()
	{
		if (front == NULL) 
		{
			cout << "Queue is empty";
			return INT_MIN;
		}

		size--;
		int value_del;
		if (front == rear) 
		{
			value_del = front->data;
			delete(front);
			front = NULL;
			rear = NULL;
		}
		else // There are more than one nodes
		{
			Node* temp = front;
			value_del = temp->data;
			front = front->link;
			rear->link = front;
			delete(temp);
		}

		return value_del;
	}
	

	// Function displaying the elements of Circular Queue
	void displayQueue()
	{
		Node* temp = front;
		cout << "\nElements in Circular Queue are: ";
		while (temp->link != front) {
			cout << temp->data << endl;
			temp = temp->link;
		}
		cout << temp->data << endl;
	}
	
};




int main()
{
	// Create a queue and initialize front and rear
	Queue q;

	// Inserting elements in Circular Queue
	q.ADDMember(14);
	q.ADDMember(22);
	q.displayQueue();
	q.ADDMember(6);

	// Display elements present in Circular Queue
	

	// Deleting elements from Circular 
	cout << "\nDeleted value =" << q.RemoveMember();
	cout << "\nDeleted value =" << q.RemoveMember();
	q.ADDMember(6);

	// Remaining elements in Circular Queue
	q.displayQueue();


	return 0;
}
