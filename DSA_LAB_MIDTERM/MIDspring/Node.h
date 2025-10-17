#pragma once
template<class type>
class Node
{
public:
	type data;
	Node* next;
public:
	Node()
	{

	}
	Node(type data, Node* next)
	{
		this->data = data;
		this->next = next;
	}

};

