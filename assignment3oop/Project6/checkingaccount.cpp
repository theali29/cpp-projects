#include "checkingaccount.h"

void checkingaccount::debit(double deb)
{
	if (account::debit(deb))
	{
		account::bal = bal - fee;
	}
}

void checkingaccount::credit(double amount)
{
	account::credit(amount);
	account::bal = bal - fee;
}

void  checkingaccount::setfee(double fe)
{
	fee = fe;
}

checkingaccount::checkingaccount() :account()
{
	fee = 0.0;
}

checkingaccount::checkingaccount(const char*a,double bal, double f) : account(a,bal)
{
	this->fee = f;
}