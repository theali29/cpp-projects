#pragma once
#include"Node.h"
template<class Type>
class Tree
{

public:
	virtual void insert_node(Type value) = 0;
	virtual void Print_inOrder(Node<Type>*node) = 0;
    virtual void Print_PostOrder(Node<Type>* node) = 0;
	virtual void Print_PreOrder(Node<Type>* node) = 0;

};

