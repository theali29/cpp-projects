#pragma once
template<class Type>
class Node
{
public:
	Type data;
	Node<Type>* next;
	Node<Type>* prev;
	Node()
	{

	}
	Node(Type data, Node<Type>* next, Node<Type>* prev)
	{
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};

