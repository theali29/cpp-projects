#include "stackADT.h"
template<class X>

class Stack :public StackADT<X>
{
	X* arr;
	int top;
	int capacity;
public:
	Stack(int size = SIZE);
	bool isempty();
	bool isfull();
	int size();
	void push(X);
	X pop();
	~Stack()
	{
		delete[]arr;
	}


};
template<class X>
Stack<X>::Stack(int size)
{
	arr = new X[size];
	capacity = size;
	top = -1;
}
template<class X>
bool Stack<X>::isempty()
{
	return top == -1;
}
template<class X>
bool Stack<X>::isfull()
{
	return top == capacity - 1;
}
template<class X>
void Stack<X>::push(X x)
{
	if (!isfull())
	{
		top++;
		arr[top] = x;
	}
	else
	{
		cout << "Stack is full" << endl;
	}
}
template<class X>
X Stack<X>::pop()
{
	if (!isempty())
	{
		return arr[top--];
	}
	else
	{
		return -1;
	}
}
template<class X>
int Stack<X>::size()
{
	return top + 1;
}