#pragma once
#include<iostream>
using namespace std;
template<class type>
class StackADT
{
public:
	virtual bool isempty() = 0;
	virtual bool isfull() = 0;
	virtual int  size() = 0;
	virtual void push(type) = 0;
	virtual type pop() = 0;
};
