#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Node
{
public:
	T data;
	Node* next;
	Node* prev;

	Node(T data)
	{
		this->data = data;
		next = prev = NULL;
	}
};

template <class T>
class dll
{
public:
	Node<T>* head;

	dll()
	{
		head = NULL;
	}

	void insertAtEnd(T d)
	{
		Node<T>* curr = head;
		Node<T>* newNode = new Node<T>(d);
		if (head == NULL)
		{
			head = newNode;
			return;
		}

		while (curr->next != NULL)
		{
			curr = curr->next;
		}

		curr->next = newNode;
		newNode->prev = curr;
	}

	void traversal()
	{
		Node<T>* curr = head;
		while (curr != NULL)
		{
			cout << curr->data << "->";
			curr = curr->next;
		}

		cout << "END";
	}

};

template <class T>
class graph
{
	int n;
	dll<T> edges[5];

public:
	graph()
	{

	}
	void addEdges(int v, T d)
	{
		edges[v].insertAtEnd(d);
	}

	void printGraph()
	{
		for (int i = 0; i < 4; i++)
		{
			cout << "\n Adjacency list of vertex " << i << " :";
			edges[i].traversal();
			printf("\n");
		}
	}
};


int main()
{
	graph<int> g1;
	int src[] = { 0,0,1,1,1,2,3 };
	int des[] = { 1,4,2,3,4,3,4 };

	for (int i = 0; i < sizeof(src) / sizeof(src[0]); i++)
	{
		g1.addEdges(src[i], des[i]);
	}

	g1.printGraph();


	return 0;
}