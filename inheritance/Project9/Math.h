#pragma once
#include "marks.h"
#include<iostream>
using namespace std;
class math :public marks
{
	int amarks;
public:
	math();
	math(int a = 0);
	void setamarks(int);
	int getamarks();
	void display()const;
	~math();
};