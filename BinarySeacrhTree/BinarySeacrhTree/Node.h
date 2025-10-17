#pragma once
template<class Type>
class Node
{
public:
	Node<Type>* right;
	Node<Type>* left;
	Type key;
	int count;
	Node()
	{
		
		key = 0;
		count = 0;
	}
	Node(const Node& n1)
	{
		key = n1.key;
		count = n1.count;
	}
	~Node()
	{

	}

};




