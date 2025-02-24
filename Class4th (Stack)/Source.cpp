﻿#include <iostream>
#define SIZE 5

using namespace std;

template<typename T>
class Stack
{
private:
	int top;
	int size;

	T container[SIZE];

public:
	Stack()
	{
		top = -1;
		size = 0;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}

	void push(T data)
	{

		if (top >= SIZE - 1)
		{
			cout << "Stack Overflow" << endl;
		}
		else
		{
			container[++top] = data;
		}
	}

	void pop()
	{
		if (empty())
		{
			cout << "Stack is empty" << endl;
		}
		else
		{
			top--;
		}
	}

	bool empty()
	{
		if (top <= -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	const int& Size()
	{
		size = top + 1;

		return size;
	}

	const T& Top()
	{
		return container[top];
	}

};


int main()
{
	Stack<int> stack;

	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);
	stack.push(50);
	stack.push(60);

	cout << "Stack Size : " << stack.Size() << endl;

	while (stack.empty() == false)
	{
		cout << stack.Top() << endl;

		stack.pop();
	}

	return 0;
}