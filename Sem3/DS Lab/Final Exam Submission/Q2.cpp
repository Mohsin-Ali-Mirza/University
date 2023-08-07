#include <iostream>
using namespace std;

template <class T>
class BTNode
{
public:
	T data;
	BTNode* right;
	BTNode* left;

	BTNode(T data)
	{
		this->data = data;
		right = left = NULL;
	}
};

template <class T>
class BST
{
public:
	BTNode<T>* root;
	bool exist;

	BST()
	{
		root = NULL;
		exist = false;
	}

	void insert(BTNode<T>* &root, T d)
	{
		if (root == NULL)
		{
			root = new BTNode<T>(d);
			return;
		}
		if (d < root->data)
			insert(root->left,d);
		else if (d > root->data)
			insert(root->right, d);
	}

	void inOrder(BTNode<T>* root,T d)
	{
		static bool flag = false;
		if (root != NULL)
		{
			inOrder(root->left,d);
			
			if (flag)
			{
				cout << root->data;
				flag = false;
				exist = true;
				return;
			}
			
			if (d == root->data)
			{
				flag = true;
				inOrder(root->right,d);
				return;
			}
			
			

			inOrder(root->right,d);
		}
	}
};

int main()
{
	BST<int> b1;
	int arr[] = { 15,10,20,8,12,16,25 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		b1.insert(b1.root, arr[i]);
	}

	int num;
	cin >> num;

	b1.inOrder(b1.root,num);
	if (b1.exist == false)
		cout << "No sucessor exists for node " << num;
	return 0;
}
