#pragma once
#include "Node.h"
template<class T>
class DDL
{
public:
	Node<T>* head;
	DDL()
	{
		head = NULL;
	}
	void insert(T val)
	{
		Node<T>* newnode = new Node<T>(val);
		if (head == NULL)
		{
			head = newnode;
		}
		else
		{
			Node<T>* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			newnode->prev = temp;
			temp->next = newnode;
		}
	}
	void print()
	{
		Node<T>* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "NULL";
		cout << endl;
	}
	T maximumvalue(Node<T>*head,int max)
	{
		Node<T>* temp = head;
		if (temp == NULL)
		{
			return max;
		}
		if (head->data>max)
		{
			max = head->data;
		}
		return maximumvalue(temp->next, max);
	}
	T minimumvalue(Node<T>* head, int min)
	{
		Node<T>* temp = head;
		if (temp == NULL)
		{
			return min;
		}
		if (temp->data<min)
		{
			min = head->data;
		}
		return minimumvalue(temp->next, min);
	}
	void printinrange(Node<T>* head,int low,int high)
	{
		if (head == NULL)
			return;
		else
		{
			if (head->data >= low && head->data <= high)
			{
				cout << head->data << ",";
			}
		}
		printinrange(head->next, low, high);
	}
};

