#pragma once

template<class type>
class QueueADT
{
public:
	virtual bool isempty() const = 0;
	virtual bool isfull() const = 0;
	virtual void initializeQueue() = 0;
	virtual void enque(type) = 0;
	virtual void deque() = 0;


};

