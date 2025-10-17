#pragma once
#include"Node.h"
template<class Type>
class DoublyLinkedListADT
{
public:
	virtual void insertAtFront(Type x) = 0;
	/*virtual void insertAtEnd(Type x) = 0;
	virtual void insertNext(Type Nodevalue, Type x) = 0;
	virtual void insertbefore(Type Nodevalue, Type x) = 0;
	virtual void insertSorted(Type x) = 0;
	virtual void sorting() = 0;*/
	virtual void display() = 0;
	/*virtual Type removefromFront() = 0;
	virtual Type removefromEnd() = 0;
	virtual Type removeNext(Type Nodevalue) = 0;*/
};