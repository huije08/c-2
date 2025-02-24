﻿#include <iostream>
#define SIZE 5
using namespace std;

template<typename T>
class LinearQueue
{
private:
	int rear;

	int front;

	T container[SIZE];
public:

	LinearQueue()
	{
		rear = 0;
		front = 0;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}

	}

	void push(T data)
	{
		if (rear >= SIZE)
		{
			cout << "Linear Queue Pverflow" << endl;
		}
		else
		{
			container[rear++] = data;
		}
	}

	bool empty()
	{
		if (rear == front)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void pop()
	{
		if (empty())
		{
			cout << "Linear Queue is empty" << endl;
		}
		else
		{
			container[front++] = NULL;
		}
	}

	const T& Front()
	{
		if (empty())
		{
			cout << "Linear Queue is Empty" << endl;

			exit(1);
		}
		else
		{
			return container[front];
		}
	}

	const int& Size()
	{
		return rear - front;
	}

};

int main()
{
	LinearQueue<int> linearQueue;

	linearQueue.push(10);
	linearQueue.push(20);
	linearQueue.push(30);
	linearQueue.push(40);
	linearQueue.push(50);

	cout << "Linear Queue Size : " << linearQueue.Size() << endl;

	while (linearQueue.empty() == false)
	{
		cout << linearQueue.Front() << " ";
		linearQueue.pop();
	}

	return 0;
}