#pragma once
#include "investment.h"

investment::investment()
{
	fee = 0.0;
}
investment::investment(double f)
{
	fee = f;
}
void investment::minbal()
{
	double bl = 0.0;
	bl = account::getbalance();
	if (bl > 20000)
	{
		cout << "You can apply for investment" << endl;
	}
	else
	{

		cout << "Minimum Balance for investment is 20k rupees " << endl;
	}
}
void investment::profit()
{
	bool flag = 0;
	double bi;
	double ir;
	cout << "Enter an investment amount " << endl;
	cin >> bi;
	minbal();
		cout << "Enter an interest rate " << endl;
		cin >> ir;

		double p;
		p = bi * ir * 12;
		cout << "profit " << p << endl;

	
	

}

void  investment::setfee(double fe)
{
	fee = fe;
}


