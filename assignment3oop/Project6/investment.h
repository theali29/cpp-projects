#pragma once
#include<iostream>
using namespace std;
#include "account.h";


class investment : public account
{
	double fee;

public:
	investment();
investment(double);
void profit();
	void minbal();
	void setfee(double);

};
