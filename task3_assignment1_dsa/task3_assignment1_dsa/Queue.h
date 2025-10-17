#pragma once
#include"QueueADT.h"
#include<iostream>
using namespace std;
template<class type>
class Queue :public QueueADT<type>
{

	type* list;
	int front;
	int rear;
	int qsize;
public:
	Queue()
	{
		qsize = 10;
		list = new type[qsize];
		front = -1;
		rear = -1;
		
	}
	Queue(int size)
	{
		list = new type[size];
		front = -1;
		rear = -1;
		this->qsize = size;
	}
	bool isempty()const
	{
		if (front == -1||front>rear)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void push(type x)
	{
	
		if (rear == qsize - 1)
	    {
		return;
	    }
	    rear++;
	    list[rear] = x;
	    if (front == -1)
	    {
		front++;
	    }
    }




	type pop()
	{
		if (isempty())
		{
			cout << "Queue is Empty";
			return -1;
		}
		return front++;
	}
	type Front()
	{
		if (front == -1)
		{
			cout << "Empty!";
			return -1;
		}
		return list[front];
	}
	type top()
	{
		if (isempty())
		{
			cout << "Queue is Empty";
			return -1;
		}
		return list[front];
	}
	
};



