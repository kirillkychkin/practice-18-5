// practice-18-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template<typename T>
class Stack
{
private:

	T* storage_;
	int capacity_;
	int top;

	void resize(int capacity)
	{
		T* temp = new T[capacity];
		for (int i = 0; i < top; ++i)
		{
			temp[i] = storage_[i];
		}
		delete[] storage_;
		storage_ = temp;
		capacity_ = capacity;
	}

public:

	Stack()
	{
		capacity_ = 1;
		storage_ = new T[1];
		top = 0;
	}

	~Stack()
	{
		delete[] storage_;
	}

	void push(T item)
	{
		if (top == capacity_)
		{
			resize(capacity_ + 1);
		}
		storage_[top++] = item;
	}

	T pop()
	{
		T item = storage_[--top];
		if (top > 0)
		{
			resize(capacity_ - 1);
		}
		return item;
	}

	bool is_empty() const
	{
		return top == 0;
	}

	int size() const
	{
		return top;
	}

};

int main()
{
	Stack<int> arr;
	arr.push(12);
	arr.push(17);

	std::cout << arr.pop() << "\n";
	arr.push(9);
	std::cout << arr.pop() << "\n";
	std::cout << arr.pop() << "\n";

	Stack<double> DoubleArray;
	DoubleArray.push(4.13);
	DoubleArray.push(3.139434);
	std::cout << DoubleArray.pop() << "\n";

	Stack<std::string> StringArray;
	StringArray.push("string element 1");
	StringArray.push("stack implementation");

	std::cout << StringArray.pop() << "\n";
	std::cout << DoubleArray.pop() << "\n";
	std::cout << StringArray.pop() << "\n";

}


