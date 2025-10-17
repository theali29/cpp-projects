#pragma once
#include"QueueADT.h"
#include<iostream>
using namespace std;
template <class type>
class Queue :public QueueADT<type>
{
private:
	type* list;
	int front;
	int rear;
	int qsize;
public:
	Queue()
	{
		list = new type[10];
		front = -1;
		rear = -1;
		qsize = 10;
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
		return rear == this->qsize - 1;
	}
	void enque(type x)
	{
		if (!isfull())
		{
			if (rear == -1 && front == -1)
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
			cout << "No Space" << endl;
		}

	}
	void deque()
	{


		if (front == rear)
		{
		cout<<"\nQueue is  empty\n";
			return;
		}

		
		else {
			for (int i = 0; i < rear - 1; i++)
			{
				list[i] = list[i + 1];
			}

			rear--;
		}
		return;

	}
	void initializeQueue()
	{
		front = rear = -1;
	}
	void printqueue()
	{
		for (int i = front; i <= rear; i++)
		{
			cout << list[i] << " ";
		}
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
	type Front()
	{
		if (front == -1)
		{
			cout << "Empty!";
			return -1;
		}
		return list[front];
	}
	int size()
	{
		return rear + 1;
	}
};

