#pragma once
#include"account.h";

account::account()
{
	this->bal = 0.0;
	title = new char[size];
}
account::account(const char *a,const double ba)
{
	size = strlen(a);
	title = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		title[i] = a[i];
	}
	title[size] = '\0';
	if (ba < 0)
	{
		this->bal = 0.0;
		cout << "balance should be greater then or equal to 0.0\n";
	}
	else
	{
		this->bal = ba;
	}
}

void account::settitle(const char* t)
{
	
		 size = strlen(t);
		title = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			title[i] = t[i];
		}
		title[size] = '\0';
	
}

char *account::gettitle()
{
	return title;
}

void account::credit(double amount)
{
	if (amount < 0)
	{
		cout << "you entered -ve value i changed it for you\n";
		amount *= 1;
	}
	this->bal = amount + bal;
}
bool account::debit(double amount)
{
	if (amount > this->bal)
	{
		cout << "withdraw amount should not be greater than balance\n";
		return false;
	}
	else
	{
		this->bal = bal - amount;
		return true;
	}


}
void account::setbalance(double db)
{
	if (db < 0)
	{
		this->bal = 0.0;
		cout << "balance should be greater then or equal to 0.0\n";
	}
	else
	{
		this->bal = db;
	}
}
const double account::getbalance() const
{
	return this->bal;
}