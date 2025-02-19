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

		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			head->previous = newNode;
			newNode->next = head;

			head = newNode;
		}

		size++;

	}

	void push_back(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;

		if (tail == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->previous = tail;

			tail = newNode;
		}
		size++;
	}

	void show()
	{
		Node* currentNode = head;

		while (currentNode != nullptr)
		{
			cout << currentNode->data << " ";

			currentNode = currentNode->next;
		}
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

			if (head == tail)
			{
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				deleteNode->next->previous = nullptr;
				head = deleteNode->next;
			}

			delete deleteNode;
			size--;
		}
	}

	void pop_back()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			Node* deleteNode = tail;

			if (head == tail)
			{
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				tail->previous->next = nullptr;
				tail = tail->previous;
			}

			size--;
		}

	}

	~DoubleLinkedList()
	{
		while (head != nullptr)
		{
			pop_front();
		}
	}

private:
	int size;

	struct Node
	{
		T data;
		Node* previous;
		Node* next;
	};

	Node* head;
	Node* tail;

};


int main()
{
	DoubleLinkedList<int> doubleLinkedList;

	doubleLinkedList.push_fornt(30);
	doubleLinkedList.push_fornt(10);
	doubleLinkedList.push_fornt(20);

	doubleLinkedList.pop_back();

	doubleLinkedList.show();


	return 0;
}