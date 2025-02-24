#include <iostream>
#define SIZE 4
using namespace std;

template<typename T>
class circleQueue
{
private:
	int front;
	int rear;

	T container[SIZE];
public:
	circleQueue()
	{
		rear = SIZE - 1;
		front = SIZZE - 1;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}
	~circleQueue();


};

int main()
{
	
	return 0;
}