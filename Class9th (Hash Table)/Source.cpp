#include <iostream>
#define SIZE 6
using namespace std;

template <typename KEY, typename VALUE>
class HashTable
{
private:
	struct Node
	{
		KEY key;
		VALUE value;

		Node* next;

	};

	struct Bucket
	{
		int count;
		Node* head;
	};

	Bucket bucket[SIZE];
public:

	HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}
	}

	template <typename T>
	const int& HashFunction(T key)
	{
		unsigned int hashIndex = (int)key % SIZE;
		return hashIndex;
	}


	template<>
	const int& HashFunction(const char* key)
	{
		int hash = 0;

		for (int i = 0; i < strlen(key); i++)
		{
			hash += key[i];
		}

		int hashIndex = hash % SIZE;

		return hashIndex;
	}

	Node* CreateNode(KEY key, VALUE value)
	{
		Node* newNode = new Node;

		newNode->key = key;
		newNode->value = value;
		newNode->next = nullptr;

		return newNode;
	}

	void Insert(KEY key, VALUE value)
	{
		int hashIndex = HashFunction(key);

		Node* newNode = CreateNode(key, value);

		if (bucket[hashIndex].count == 0)
		{
			bucket[hashIndex].head = newNode;
		}
		else
		{
			newNode->next = bucket[hashIndex].head;

			bucket[hashIndex].head = newNode;
		}

		bucket[hashIndex].count++;
	}

	~HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			Node* deleteNode = bucket[i].head;
			Node* nextNode = bucket[i].head;

			if (bucket[i].head == nullptr)
			{
				continue;
			}
			else
			{
				while (nextNode != nullptr)
				{
					nextNode = deleteNode->next;

					delete deleteNode;

					deleteNode = nextNode;
				}
			}
		}
	}

	void Remove(KEY key)
	{
		int hashIndex = HashFunction(key);

		Node* currentNode = bucket[hashIndex].head;

		Node* previousNode = nullptr;

		if (currentNode == nullptr)
		{
			cout << "Not Key Found" << endl;

			return;
		}
		else
		{
			while (currentNode != nullptr)
			{
				if (currentNode->key == key)
				{
					if (currentNode == bucket[hashIndex].head)
					{
						bucket[hashIndex].head = currentNode->next;
					}
					else
					{
						previousNode->next = currentNode = > next;
					}

					bucket[hashIndex].count--;

					delete currentNode;

					return;
				}
				else
				{
					previousNode = currentNode;

					currentNode = currentNode->next;
				}
			}
		}
	}

};



int main()
{

	HashTable<const char*, int> hashTable;

	hashTable.Insert("Sword", 10000);
	hashTable.Insert("Armor", 5000);

	hashTable.Remove("Hat");
	return 0;
}