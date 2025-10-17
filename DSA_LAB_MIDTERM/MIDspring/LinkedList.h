#pragma once
#include"Node.h"
#include<iostream>
using namespace std;
template<class Type>
class LinkedList
{
protected:
	Node<Type>* head;
	


public:
	LinkedList()
	{

	}
	virtual void insertAtEnd(Type) = 0;
	virtual Type deleteFromHead() = 0;
	virtual bool isEmpty() = 0;
	virtual void display() = 0;

};
template<class Type>
class MyLL :public LinkedList<Type>
{
public:
	/*Node<Type>* front = NULL;
	Node<Type>* rear = NULL;*/
	MyLL()
	{
		LinkedList<Type>::head = NULL;
	}
	bool isEmpty()
	{
		return LinkedList<Type>::head== NULL;
	}
	void insertAtEnd(Type x)
	{
		Node<Type>* newnode = new Node<Type>;
		newnode->data = x;
		newnode->next = NULL;
		/*if (front == NULL)
		{
			front = newnode;
			rear = newnode;
		}
		else
		{
			rear->next = newnode;
			rear = newnode;
			return;
		}*/
		Node<Type>* temp = LinkedList<Type>::head;
		if (LinkedList<Type>::head == NULL) {
			LinkedList<Type>::head = newnode;
			return;
		}
		else
		{
			while (temp->next != NULL)
			{
				temp = temp->next;
			}

			temp->next = newnode;
			return;
		}
	}
	Type deleteFromHead()
	{
		int i;
		if (isEmpty())
		{
			cout << "QUEUE is empty";
		}
		Node<Type>* temp = LinkedList<Type>::head;

		/*if (front == rear)
		{
			delete front;
			front = rear = NULL;
		}
		else
		{
			i = front->data;
			temp = front;
			front = front->next;
        } */
		/*return i;*/
		if (LinkedList<Type>::head == NULL)
		{
			return NULL;
		}
		i = temp->data;
		LinkedList<Type>::head = temp->next;


		delete temp;
		return i;
	}
	Type tqfront()
	{
		int i;
		i = LinkedList<Type>::head->data;
		return i;
	}
	void display()
	{
		Node<Type>* temp = LinkedList<Type>::head;
		if (temp != NULL) {
			cout << "The Queue contains: ";
			while (temp != NULL) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
		else
		{
			cout << "The queue is empty.\n";
		}
	}
};



