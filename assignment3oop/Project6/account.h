
#pragma once
#include<iostream>
using namespace std;
class account
{
protected:
	double bal;
	char* title;

public:
	int size = 0;
	account();
	account(const char*,const double);
	void settitle(const char* atitle);
	char* gettitle();
	void credit(double);
	bool debit(double);
	void setbalance(double);
	const double getbalance() const;

};