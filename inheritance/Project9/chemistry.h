#pragma once
#include "marks.h"
#include<iostream>
using namespace std;
class chemistry :public marks
{
	int cmarks;
public:
	chemistry();
	chemistry(int a = 0);
	void setcmarks(int);
	int getcmarks();
	void display()const;
	~chemistry();
};