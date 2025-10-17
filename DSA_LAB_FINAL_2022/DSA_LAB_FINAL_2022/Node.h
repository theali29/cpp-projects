#pragma once
#include<iostream>
using namespace std;
template<class T>
class Node
{
public:
	T data;
	Node<T>*prev;
	Node<T>* next;
	Node(int d)
	{
		data = d;
		prev = next = NULL;
	}
	~Node()
	{

	}
};

