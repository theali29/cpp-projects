#pragma once
#include<iostream>
using namespace std;
template<class T>
class Node2
{
public:
	T key;
	Node2<T>* right;
	Node2<T>* left;

	Node2(T data)
	{
		key = data;
		right = left = NULL;
	}
};

