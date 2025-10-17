#pragma once
#include<iostream>
using namespace std;
#include "account.h";
#include"checkingaccount.h";

class checkingaccount : public account
{
	double fee;

public:
	checkingaccount();
	checkingaccount(const char*,double, double);
	void debit(double);
	void credit(double);
	void setfee(double);

};

