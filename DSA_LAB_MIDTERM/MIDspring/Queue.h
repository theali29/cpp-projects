#pragma once
#include"LinkedList.h"
template<class Type>

class Queue
{
public:
	MyLL<Type>obj;
	int currentSize;
public:
	virtual bool isEmpty() = 0;
	virtual void enqueue(Type) = 0;
	virtual Type dequeue() = 0;
	virtual void display() = 0;
};

template<class Type>
class MyQueue :public Queue<Type>
{
public:

	bool isEmpty()
	{
		bool a;
		a=Queue<Type>::obj.isEmpty();
		if (a == true)
		{
			return true;

		}
		else
		{
			return false;
		}
	}
	
	void enqueue(Type x)
	{
		Queue<Type>::obj.insertAtEnd(x);
		Queue<Type>::currentSize++;

	}
	Type size()
	{
		return Queue<Type>::currentSize;
	}
	Type dequeue()
	{
		int j;
		j=Queue<Type>::obj.deleteFromHead();
		return j;
	}
	Type tfront()
	{
		int c = 0;
		c=Queue<Type>::obj.tqfront();
		return c;
	}
	 void display()
	 {
		 Queue<Type>::obj.display();
     }
};


