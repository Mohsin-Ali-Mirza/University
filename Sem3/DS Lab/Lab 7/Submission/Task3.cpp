#include <iostream>
#include <cwctype>
using namespace std;

const int Max = 10;

class stack
{
	int top;

public:
	char a[Max];

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

	bool push(char x)
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

	char pop()
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

	char peek()
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

int prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

string infixToPostFix(string exp)
{
	stack s1;
	string postexp;
	s1.push('#');
	for (char ch : exp)
	{
		if (iswalnum(ch))
		{
			postexp += ch;
		}
		else if (ch == '(')
		{
			s1.push(ch);
		}
		else if (ch == '^')
		{
			s1.push(ch);
		}
		else if (ch == ')')
		{
			while (!s1.isEmpty() && s1.peek() != '(')
			{
				postexp+=s1.pop();
			}
			s1.pop();			//maybe only pop
		}
		else
		{
			while (!s1.isEmpty() && prec(ch) <= prec(s1.peek()))
			{
				postexp += s1.pop();
			}

			s1.push(ch);
		}
	}
	while (!s1.isEmpty())
	{
		postexp += s1.pop();
	}
	return postexp;
}



int main()
{
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
	string postfix = infixToPostFix(exp);
	cout << postfix;

	return 0;
}