#include <iostream>

using namespace std;

template<typename T>
class DoubleLinkedList
{
public:
	
	DoubleLinkedList()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	void push_fornt(T data)
	{
		Node* newNode = new Node;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;

			newNode->data = data;
			newNode->next = nullptr;
		}
		else
		{
			newNode
		}


	}
private:
	int size;

	struct Node
	{
		T data;
		Node * previous;
		Node * next;
	};

	Node* head;
	Node* tail

};


int main()
{


	return 0;
}