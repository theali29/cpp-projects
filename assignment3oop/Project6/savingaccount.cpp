#include "savingaccount.h"
savingaccounts::savingaccounts() :account()
{
	this->inrate = 0.0;
}
savingaccounts::savingaccounts(const char*a,double ba, double i) : account(a,ba)
{
	this->inrate = i;
}
double savingaccounts::calintrest()
{
	double temp = this->inrate / 100;
	temp = temp * this->getbalance();
	return temp;
}