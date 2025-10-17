#pragma once
#include"account.h"
#include<iostream>
using namespace std;
class savingaccounts:public account
{
	double inrate;
public:
	savingaccounts();
	savingaccounts(const char*a,double, double);
	double calintrest();



};

