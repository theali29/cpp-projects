#pragma once
#include "marks.h"
#include<iostream>
using namespace std;
class physics :public marks
{
	int bmarks;
public:
	physics();
	physics(int b = 0);
	void setbmarks(int);
	int getbmarks();
	void display()const;
	~physics();
};