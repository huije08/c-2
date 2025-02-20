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
			newNode->next = head->next;

			head->next = newNode;

			head = newNode;
		}
		size++;
	}

	void push_front(T data)
	{
		Node* newNode = new Node;

		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;

			head->next = newNode;
		}
		size++;
	}

	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			Node* deleteNode = head;

			if (head == head->next)
			{
				head == nullptr;
			}
			else
			{
				head->next = deleteNode->next;
			}
			delete deleteNode;

			size--;
		}

	}

	void show()
	{
		if (head != nullptr)
		{
			Node* currentNode = head->next;

			for (int i = 0; i < size; i++)
			{
				cout << currentNode->data << " ";
				currentNode = currentNode->next;
			}
		}
	}

	

	~CircleLinkedList()
	{
		while (head != nullptr)
		{
			pop_front();
		}
	}

};

int main()
{
	CircleLinkedList<int> circleLinkedList;

	circleLinkedList.push_back(10);
	circleLinkedList.push_back(20);
	circleLinkedList.push_back(30);
	
	
	circleLinkedList.pop_front();

	circleLinkedList.show();

	return 0;
}