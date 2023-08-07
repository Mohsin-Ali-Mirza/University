#include <iostream>
using namespace std;

const int Max = 10;

class stack
{
	int top;

public:
	int a[Max];				
	
	stack()
	{
		top = -1;			
	}

	bool isFull()
	{
		return (top >= (Max - 1));
	}

	bool isEmpty()
	{
		return (top < 0);
	}

	bool push(int x)
	{
		if (isFull())
		{
			cout << "Stack OverFlow";
			return false;
		}
		else
		{
			a[++top] = x;
			cout << x << " Pushed to the stack\n";
			return true;
		}
	}

	int pop()
	{
		if (isEmpty())
		{
			cout << "Stack UnderFlow";
			return 0;
		}

		else
		{
			return a[top--];
		}
	}

	int peek()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty";
			return 0;
		}
		else
		{
			return a[top];
		}
	}
};

int main()
{
	stack s1;
	for (int i = 10; i > -1; i--)
	{
		s1.push(i);
	}

	cout << "\n";
	while (!s1.isEmpty())
	{
		cout << s1.peek()<<"\n";
		int p = s1.pop();
	}

	cout << "\n" << s1.peek();


	return 0;
}