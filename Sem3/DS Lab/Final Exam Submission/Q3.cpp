#include <iostream>
#include<math.h>
#include <stack>
using namespace std;

class HashNode
{
public:
	int value=0;
	int key;

	HashNode(int k)
	{
		this->key = k;
	}
};

class HashMap
{
	HashNode** arr;
	int capacity;
	int size;
public:

	HashMap()
	{

		capacity = 12;
		size = 0;
		arr = new HashNode * [capacity];
		for (int i = 0; i < capacity; i++)
			arr[i] = NULL;

	}

	int HashFun_Div(int k)
	{
		return k % capacity;
	}


	void insert(int k)
	{
		HashNode* temp = new HashNode(k);
		int hashIndex = HashFun_Div(k);

		while (arr[hashIndex] != NULL && arr[hashIndex]->key != k && arr[hashIndex]->key != -1)
		{
			hashIndex++;
			hashIndex %= capacity;
		}

		if (arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
			size++;

		if (arr[hashIndex] != NULL && arr[hashIndex]->key == k)
		{
			arr[hashIndex]->value++;
		}
		else
		arr[hashIndex] = temp;
	}

	int findMaxKey()
	{
		int max = INT_MIN;
		int max_key  = INT_MIN;
		for (int i = 0; i < capacity; i++)
		{
			if (arr[i] != NULL && arr[i]->key != -1)
				if (arr[i]->value > max)
				{
					max = arr[i]->value;
					max_key = arr[i]->key;
				}
		}
		cout << "MAX KEY:" << max_key<<endl;
		return max_key;
	}

	void display()
	{
		for (int i = 0; i < capacity; i++)
		{
			if (arr[i] != NULL && arr[i]->key != -1)
				cout << "key:" << arr[i]->key << " val=" << arr[i]->value << endl;
		}
	}
};

void findIndex(int* arr, int d,int n)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == d)
		{
			cout << "Index is:"<<i;
			break;
		}
	}
}

int main()
{
	HashMap h1;
	int arr[] = { 4,3,6,8,4,6,2,4,5,9,7,4};
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		h1.insert(arr[i]);

	int n = sizeof(arr) / sizeof(arr[0]);

	findIndex(arr, h1.findMaxKey(), n);


	return 0;
}