#pragma once
#include"DoublyLinkedListADT.h"
#include<iostream>
using namespace std;
template<class Type>
class DoublyLinkedList :public DoublyLinkedListADT<Type>
{

public:
	Node<Type>* tail;
	DoublyLinkedList()
	{
		tail = NULL;
	}
	bool empty()
	{
		return tail == NULL;
	}
	void insertAtFront(Type x)
	{
		Node<Type>* newnode = new Node<Type>;
		newnode->data = x;
		if (tail == NULL)
		{
			tail = newnode;
			tail->next = tail;
		}
		else
		{
			newnode->next = tail->next;
			tail->next->prev = newnode;
			tail->next = newnode;
		}
	}
	void insertAtEnd(Type x)
	{
		Node<Type>* temp = head;
		Node<Type>* newnode = new Node<Type>;
		newnode->data = x;
		if (head == NULL)
		{
			head = newnode;
		}

		else
		{
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			newnode->prev = temp;
			temp->next = newnode;

		}
	}
	void insertNext(Type Nodevalue, Type x)
	{
		Node<Type>* temp = head;
		Node<Type>* newnode = new Node<Type>;
		newnode->data = x;
		if (head == NULL)
		{
			head = newnode;
		}
		else
		{
			while (temp->data != Nodevalue)
			{
				temp = temp->next;
			}
			newnode->prev = temp;
			newnode->next = temp->next;
			temp->next = newnode;
		}
	}
	void sorting()
	{
		Node<Type>* temp = head;
		Node<Type>* i = temp;
		Node<Type>* j = i->next;
		for (i = temp; i != NULL; i = i->next)
		{
			for (j = i->next; j != NULL; j = j->next)
			{
				if (i->data > j->data)
				{
					swap(i->data, j->data);

				}
			}
		}
	}
	void insertSorted(Type x)
	{
		Node<Type>* current = head;
		Node<Type>* newnode = new Node<Type>;
		newnode->data = x;

		while (head == NULL || current->data >= newnode->data)
		{
			newnode->next = head;
			head->prev = newnode;
			head = newnode;
			return;
		}
		while (current->next != NULL && current->next->data < newnode->data)
		{
			current = current->next;
		}
		newnode->prev = current;
		newnode->next = current->next;
		current->next = newnode;
	}
	int removefromFront()
	{
		Node<Type>* temp = head;
		int i = 0;
		if (head == NULL)
		{
			return NULL;
		}
		else
		{
			i = temp->data;
			temp->next->prev = NULL;
			head = temp->next;
			delete temp;
			return i;
		}
	}
	void insertbefore(Type Nodevalue, Type x)
	{

		Node<Type>* temp = head;
		Node<Type>* newnode = new Node<Type>;
		newnode->data = x;
		if (head == NULL)
		{
			head = newnode;
		}
		else
		{
			while (temp->data != Nodevalue)
			{
				temp = temp->next;
			}
			temp = temp->prev;
			newnode->prev = temp;
			newnode->next = temp->next;
			temp->next = newnode;
		}

	}
	Type removeNext(Type Nodevalue)
	{
		Node<Type>* temp = head;
		int i = 0;
		if (head == NULL)
		{
			return NULL;
		}
		else
		{
			while (temp->data != Nodevalue)
			{
				temp = temp->next;
			}
			if (temp->next == NULL)
			{
				cout << "The next node is NULL " << endl;
				return -1;
			}
			temp = temp->next;
			i = temp->data;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
			return i;
		}
	}
	Type removefromEnd()
	{
		Node<Type>* temp = head;
		int i = 0;
		if (head == NULL)
		{
			return NULL;
		}
		else
		{
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			i = temp->data;
			temp->prev->next = NULL;
			delete temp;
		}
	}
	int SizeofList()
	{
		int size = 0;
		Node<Type>* temp = head;
		while (temp != NULL)
		{
			temp = temp->next;
			size++;
		}

		return size;
	}
	void display()
	{
		Node<Type>* temp = tail->next;
		do
		{
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp->next != tail->next);
		cout << endl;
	}
};

