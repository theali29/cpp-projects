#pragma once
#include<iostream>
using namespace std;
class marks
{
	int rollnumber;
	char* name;
	int mark_s;
public:
	int size;
	marks();
	marks(int a, const char* b, int c);
	void setrollnumber(int);
	void setname(char*);
	void setmark_s(int);
	int getrollnumber();
	int getmark_s();
	char* getname();
	void display()const;
	~marks();
};