//Mohammad Ali
//Creating bank account withdraw/deposit using constructors
//setter getter functions
//
#include<iostream>
#include<string>
using namespace std;
class bankaccount
{
private:
	char* accounttitle;
	char* accountnumber;
	float balance = 0;
	int size = 0;
	int size1 = 0;
public:

	bankaccount()
	{
		
		accounttitle = new char[size1];
		accounttitle[size1] = { '\0' };
		accountnumber = new char[size];
		accountnumber[size] = { '\0' };
		balance = 20000;
	}
	bankaccount(const char* an, const char* at, float b)
	{
		size = strlen(an);
		size1 = strlen(at);
		accounttitle = new char[size1];

		accountnumber = new char[size];
		for (int i = 0; i < size; i++)
		{
			accountnumber[i] = an[i];

		}
		accountnumber[size] = { '\0' };

		for (int i = 0; i < size1; i++)
		{
			accounttitle[i] = at[i];

		}
		accounttitle[size1] = { '\0' };

		balance = b;
	}
	void change(const char* acn, const char* act)
	{
		delete[]accountnumber;
		delete accounttitle;
		size = strlen(acn);
		size1 = strlen(act);
		accountnumber = new char[size];
		for (int i = 0; i < size; i++)
		{
			accountnumber[i] = acn[i];
		}
		accountnumber[size] = { '\0' };
		accounttitle = new char[size1];
		for (int i = 0; i < size1; i++)
		{
			accounttitle[i] = act[i];
		}
		accounttitle[size1] = { '\0' };
	}
	void depositamount()
	{
		float ad;
		cout << "Enter an amount to deposit " << endl;
		cin >> ad;
		balance = balance + ad;
		cout << "Balance updated after depositing " << balance << endl;
	}
	void withdrawamount()
	{
		float wa;
		wa = balance * 0.2;

		if (wa < balance)
		{
			balance = balance - wa;
		}
	}
	void setaccountitle()
	{


		char* at = new char[size1];


		delete[]at;

	}
	char getaccounttitle()
	{
		return *accounttitle;
	}
	void setaccountnumber()
	{

		char* an = new char[size];

		delete[]an;
	}

	char getaccountnumber()
	{
		return*accountnumber;
	}
	void setbalance()
	{
		if (balance > 0)
		{
			balance = balance;
		}
	}
	float getbalance()
	{
		return balance;
	}
	void display()
	{
		cout << "Name:" << accounttitle << endl;
		cout << "Account Number " << accountnumber << endl;
		cout << "Balance:" << balance << endl;

	}

	bankaccount(const bankaccount& bt)
	{
		size = bt.size;
		size1 = bt.size1;
		accounttitle = new char[size1];
		accountnumber = new char[size];
		for (int i = 0; i < size1; i++)
		{
			accounttitle[i] = bt.accounttitle[i];
		}
		for (int i = 0; i < size; i++)
		{
			accountnumber[i] = bt.accountnumber[i];
		}
		balance = bt.balance;

	}
	~bankaccount()
	{
		delete[]accounttitle;
		delete[]accountnumber;
	}
};
int main()
{
	bankaccount obj1("123-456-789","Customer Name",20000);
	obj1.withdrawamount();
	cout << "Object 1 displaying " << endl;
	obj1.display();
	cout << "-----------------------" << endl;
	bankaccount obj2("253-986-486", "Ali", 20000);

	obj2.setaccountitle();
	obj2.setaccountnumber();
	obj2.depositamount();
	cout << "obj2 displaying" << endl;
	obj2.display();
	cout << "-----------------------" << endl;
	obj2.setaccountnumber();
	bankaccount obj3(obj2);
	obj3.setaccountitle();
	obj3.change("123-456-789", "Usama");
	obj3.depositamount();
	obj3.withdrawamount();
	cout << "-----------------------" << endl;
	cout << "Object 3 displaying " << endl;
	obj3.display();
	system("pause");
	return 0;

}