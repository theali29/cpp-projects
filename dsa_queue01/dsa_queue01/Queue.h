#pragma once
#include"QueueADT.h"
#include<iostream>
using namespace std;
template<class type>
class Queue :public QueueADT<type>
{
protected:
	type* list;
	int front;
	int rear;
	int qsize;
public:
	Queue()
	{
	    list=new type[10];
		front=-1;
		rear=-1;
		qsize=10;
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
		return front == -1;
	}
	bool isfull()const
	{
		return rear == qsize-1;
	}
	void enque(type x)
	{
		if (!isfull())
		{
			if (front == -1 && rear == -1)
			{
				rear++;
				front++;
				list[rear] = x;
			}
			else
			{
				rear++;

				list[rear] = x;
			}
		}
		else
		{
			cout << "Queue is Full " << endl;
		}
	}
	type tfront()
	{
		if(!isempty())
		{
			return list[front];
		}
		else
		{
			return -1;
		}
		
	}
	type deque()
	{
		if (!isempty())
		{
			if (front <= rear)
			{
				front++;
				return list[front];

			}
			else
			{
				cout << "Insertion not possible " << endl;
			}
		}
		else
		{
			cout << "It is empty" << endl;
			return 0;
		}
	}
	
	void initializeQueue()
	{
		front = -1;
		rear = -1;
	}
	void printqueue()
	{
	
		for (int i = front; i <= rear; i++)
		{
			cout << list[i] << " ";
		}
	
		cout << endl;
	}
};