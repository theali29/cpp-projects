//#include "Stack.h"

//template<class X>
//Stack<X>::Stack(int size)
//{
//	arr = new X[size];
//	capacity = size;
//	top = -1;
//}
//template<class X>
//bool Stack<X>::isempty()
//{
//	return top == -1;
//}
//template<class X>
//bool Stack<X>::isfull()
//{
//	return top == capacity-1;
//}
//template<class X>
//void Stack<X>::push(X x)
//{
//	if (!isfull())
//	{
//		top++;
//		arr[top] = x;
//	}
//	else
//	{
//		cout << "Stack is full" << endl;
//	}
//}
//template<class X>
//X Stack<X>::pop()
//{
//	if (!isempty())
//	{
//		return arr[top--];
//	}
//	else
//	{
//		return -1;
//	}
//}
//template<class X>
//int Stack<X>::size()
//{
//	return top + 1;
//}
//
