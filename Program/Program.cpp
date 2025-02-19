#include <iostream>

using namespace std;

template<typename T>
class CircleLinkedList
{
private:
	int size;
	struct Node
	{
		T data;
		Node* next;
	};
	Node* head;


public:
	CircleLinkedList()
	{
		head = nullptr;
		size = 0;
	}

	void push_back(T data)
	{
		Node* newNode = new Node;

		if (head == nullptr)
		{
			head = newNode;

			
			newNode->next = head;
		}
		else
		{
			newNod->next = head->next;

			head->next = newNode;

			head = newNode;
		}
		size++;
	}

	void show()
	{

	}

	~CircleLinkedList()
	{
	}

};

int main()
{



	return 0;
}