#include <iostream>
#define SIZE 10
using namespace std;

template <typename T>
class AdjacencyList
{
private:
	struct Node
	{
		T data;
		Node* next;

		Node(T data, Node* link = nullptr)
		{
			this->data = data;
			next = link;
		}
	};

	int size;
	T vertex[SIZE];
	Node* list[SIZE];
public:
	AdjacencyList()
	{
		size = 0;

		for (int i = 0; i < SIZE; i++)
		{
			list[i] = NULL;
			vertex[i] = NULL;
		}

	}

	void push(T data)
	{
		if (size >= SIZE)
		{
			cout << "Adjacency List Overflow" << endl;
		}
		else
		{
			vertex[size++] = data;
		} 
	}
	
	void edge(int i, int j)
	{
		if (size <= 0)
		{
			cout << "Adjacency List is Empty";
		}
		else if
		{
			cout << "Index Out of Range" << endl;
		}
		else
		{
			list[i] = new Node(vertex[j], list[i]);
			list[i] = new Node(vertex[i], list[j]);
		}
	}
};


int main()
{

}