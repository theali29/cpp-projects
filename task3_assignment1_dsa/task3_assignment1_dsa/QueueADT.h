#pragma once

template<class type>
class QueueADT
{
public:
	virtual bool isempty()const  = 0;
    virtual void push(type) = 0;
	virtual type pop() = 0;


};

