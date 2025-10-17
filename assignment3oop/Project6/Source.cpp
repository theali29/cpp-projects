#include "account.h";
#include "savingaccount.h";
#include "checkingaccount.h";
#include"investment.h";

int main()
{
	account obName;
	obName.settitle("Talha Riaz");
	cout << "Title : " << obName.gettitle();
	cout << endl;

	 obName.setbalance(2990.1);
	cout << "Balance : " << obName.getbalance();
	cout << endl;

	savingaccounts Talha("Talha Riaz ",5000, 10);
	cout << "Interest : " << Talha.calintrest();
	cout << endl;

	obName.debit(500);
	cout << "Deposited Ammount : " << obName.getbalance();
	cout << endl;

	obName.credit(200);
	cout << "Balance : " << obName.getbalance();
	cout << endl;

	checkingaccount ob1("Talha Riaz", 100, 23);
	ob1.debit(20)
		;
	cout << "Withdrawing Ammount : " << ob1.getbalance();
	investment ir;

	cout << "Investment " << endl;
	ir.minbal();
    ir.profit();
	ir.setfee(20);
}