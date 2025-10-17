#pragma once
#include<iostream>
#include<string>
using namespace std;
template<class type>
class List
{
	type* arr;
	int maxSize;
	int currentSize;

public:
	List();
	List(type* arr, int ms, int cs);
	List(List& l1);
	virtual void addElementAtFirstIndex(type) = 0;
	virtual void addElementAtLastIndex(type) = 0;
	virtual void removeElementFromEnd() = 0;
	virtual void removeElementFromStart() = 0;



	~List();
};

