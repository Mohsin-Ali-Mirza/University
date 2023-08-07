#include <iostream>
using namespace std;

class HashNode
{
public:
	int key;
	int value;
	HashNode(int k, int v)
	{
		this->key = k;
		this->value = v;
	}
};

class HashMap
{
private:
	HashNode** arr;
	int capacity;
	int size;
public:
	HashMap()
	{
		capacity = 20;
		size = 0;
		arr = new HashNode *[capacity];
		for (int i = 0; i < capacity; i++)
			arr[i] = NULL;

	}
	int HashFun(int k)
	{
		return k % capacity;
	}

	void Insert(int k, int v)
	{
		HashNode* temp = new HashNode(k, v);
		int hashIndex = HashFun(k);

		while (arr[hashIndex] != NULL && arr[hashIndex]->key != k && arr[hashIndex]->key != -1)
		{
			hashIndex++;
			hashIndex %= capacity;
		}

		if (arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
		{
			size++;
		}
		arr[hashIndex] = temp;
	}

	int Delete(int key)
	{
		HashNode* removeIndex = new HashNode(-1, -1);
		int hashIndex = HashFun(key);
		while (arr[hashIndex != NULL])
		{
			if (arr[hashIndex]->key == key)
			{
				HashNode* temp = arr[hashIndex];
				arr[hashIndex] = removeIndex;
				size--;
				return temp->value;
			}
			hashIndex++;
			hashIndex %= capacity;
		}
		return NULL;
	}

	int get(int key)
	{
		int hashIndex = HashFun(key);
		int counter = 0;

		while (arr[hashIndex] != NULL)
		{
			if (counter++ > capacity)
				return NULL;

			if (arr[hashIndex]->key == key)
				return arr[hashIndex]->value;

			hashIndex++;
			hashIndex %= capacity;
		}

		return NULL;

	}

	void display()
	{
		for (int i = 0; i < capacity; i++)
		{
			if(arr[i]!= NULL && arr[i]->key != -1)
				cout << "key = " << arr[i]->key<< " value = "<< arr[i]->value << endl;
		}
	}
	~HashMap()
	{
		for (int i = 0; i < capacity; i++)
			delete arr[i];
		delete[]arr;
	}
};

int main()
{
	HashMap h1;
	h1.Insert(1, 1);
	h1.Insert(2, 2);
	h1.Insert(2, 3);
	h1.display();



	return 0;
}