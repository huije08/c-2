#include <iostream>

using namespace std;

template<typename T>
class SingleLinkedList
{
public:
	SingleLinkedList()
	{
		size = 0;
		head = nullptr;
	}

	void push_front(T data)
	{
		Node* newNode = new Node;

		if (head == nullptr)
		{
			head = newNode;

			newNode->data = data;
			newNode->next = nullptr;
		}
		else
		{
			newNode->data = data;
			newNode->next = head;

			head = newNode;
		}

	}

	void push_back(T data)
	{
		Node* newNode = new Node;

		if (head == nullptr)
		{
			head = newNode;

			newNode->data = data;
			newNode->next = nullptr;
		}
		
	}


private:
	int size;

	struct Node
	{
		T data;
		Node* next;

	};

	Node* head;

};




int main()
{
	SingleLinkedList<int> singleLinkedList;

	singleLinkedList.push_front(10);
	singleLinkedList.push_front(20);

	return 0;
}