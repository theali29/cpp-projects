#pragma once
#include<iostream>
using namespace std;
template<class Type>
class Node
{
public:
	Node<Type>* left;
	Node<Type>* right;
	Node<Type>* parent;
	Type data;
	bool color;
	Node()
	{
		color = 0;
    }
	~Node()
	{

	}
};

