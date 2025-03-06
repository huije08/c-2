#include <iostream>
#include <queue>
#define SIZE 5
using namespace std;

template <typename T>
class PriorityQueue
{
private:
	int index;
	T container[SIZE];

public:
	PriorityQueue()
	{
		index = 0;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL
		}
	}

	void push(T data)
	{
		if (index + 1 >= SIZE)
		{
			cout << "Priority Queue Overflow" << endl;
		}
		else
		{
			container[++index] = data;

			int child = index;

			int parent = child / 2;

			while (child > 1)
			{
				if (container[parent] < container[child]) {
					std::swap(container[parent], container[child]);
				}

				child = parent;
				parent = child / 2;
			}
		}
	}

	con
};



int main()
{
	priority_queue<int> priorityQueue;

	priorityQueue.push(30);
	priorityQueue.push(2);
	priorityQueue.push(77);
	priorityQueue.push(15);
	
	while (priorityQueue.empty() == false)
	{
		cout << priorityQueue.top() >> " ";

		priorityQueue.pop();
	}
	return 0;
}