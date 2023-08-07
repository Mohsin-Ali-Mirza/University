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
		arr = new HashNode * [capacity];
		for (int i = 0; i < capacity; i++)
			arr[i] = NULL;

	}

	int selectHash(int key, int value, int choose)
	{
		switch (choose)
		{
		case 0:
			RadixHash(key);
			break;
		case 1:
			FoldingHash(key);
			break;

		case 2:
			MultiplicationHash(key);
			break;

		case 3:
			MidSquareHash(key);
			break;

		case 4:
			HashFun(key);
			break;
		}
	}

	int MultiplicationHash(int k)
	{
		double c = 0.3;
		double intPart;
		double n = k * c;
		double frac = modf(n, &intPart);
		frac *= size;
		frac = floor(frac);
		return ((int)frac % size);
	}
	int MidSquareHash(int k)
	{
		return (k * k) % size;
	}
	int FoldingHash(int k)
	{
		return ((k % 10) + ((k / 10) % 10) + ((k / 100) % 10) % size);
	}
	int RadixHash(int k)
	{
		return ((k / 10) % size);
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
			hashIndex++;					//Change Over Here
			hashIndex %= capacity;			//Change Over Here
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

			hashIndex++;				//Change Over Here
			hashIndex %= capacity;		//Change Over here
		}

		return NULL;

	}

	void display()
	{
		for (int i = 0; i < capacity; i++)
		{
			if (arr[i] != NULL && arr[i]->key != -1)
				cout << "key = " << arr[i]->key << " value = " << arr[i]->value << endl;
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