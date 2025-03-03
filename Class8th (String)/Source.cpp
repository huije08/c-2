#include <iostream>
using namespace std;

class String
{
private:
	int size;
	char* pointer;

public:
	String()
	{
		size = 0;
		pointer = nullptr;
	}

	void operator = (const char* word)
	{
		size = strlen(word) + 1;

		if (pointer == nullptr)
		{
			pointer = new char[size];

			for (int i = 0; i < size; i++)
			{
				pointer[i] = word[i];
			}
		}
		else
		{
			char* newPointer = new char[size];

			for (int i = 0; i < size; i++)
			{
				newPointer[i] = word[i];
			}

			delete[] pointer;

			pointer = newPointer;
		}
	}

	const int& Size()
	{
		return size - 1;
	}

	const char& operator [] (const int& index)
	{
		return pointer[index];
	}

	~String()
	{
		if (pointer != nullptr)
		{
			delete[] pointer;
		}
	}

	void Append(const char* word)
	{
		size = strlen(pointer) + strlen(word + 1);

		char* newPointer = new char;

		for (int i = 0; i < strlen(pointer); i++)
		{
			newPointer[i] = pointer[i];
		}
		for (int i = 0; i < strlen(word); i++)
		{
			newPointer[strlen(pointer) + 1] = word[i];
		}

		if (pointer != nullptr)
		{
			delete[] pointer;
		}

		pointer = newPointer;
	}

	unsigned long long Find(const char* word)
	{
		int length = (size - 1) - strlen(word);

		int i = 0;
		int j = 0;

		for (i = 0; i < length; i++)
		{
			for (j = 0; j < strlen(word); j++)
			{
				if (pointer[i + j] != word[j])
				{
					break;
				}
			}

			if (j == strlen(word))
			{
				return i;
			}

		}

		return 18446744073709551615;

	}

};

int main()
{
	String string;

	string = "key";




	return 0;
}