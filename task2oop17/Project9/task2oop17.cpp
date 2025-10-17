#include<iostream>
using namespace std;

class Address
{
	
public:
	int StreetNo;
	int HouseNo;
	char* city;
	int size = 0;
	Address()
	{
		StreetNo = 0;
		HouseNo = 0;
		city = new char[size];

	}
	Address(int sn, int hn, const char* c)
	{
		size = strlen(c);
		city= new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			city[i] = c[i];
		}
		city[size] = '\0';
		StreetNo = sn;
		HouseNo = hn;
	}

};
class Person
{
public:
	char* name;
	Address add;
public:
	int size = 0;
	Person()
	{
		name = new char[size];

	}
	Person(const char* n,int sn,int hn,const char* c)
	{
		size = strlen(n);
		name = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			name[i] = n[i];
		}
		name[size] = '\0';
		add.StreetNo = sn;
		add.HouseNo = hn;
		size = strlen(c);
		add.city = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			add.city[i] = c[i];
		}
		add.city[size] = '\0';

	}
	virtual void display()
	{

	}
};
class SalariedEmployee :public Person
{
public:
	double monthlypay;
public:
	SalariedEmployee(double mp, const char* n, int sn, int hn, const char* c) :Person(n, sn, hn, c)
	{
		monthlypay = mp;
	}
	void display()
	{
		cout << name << " " << add.StreetNo << " " << add.HouseNo << " " << add.city << endl;
		cout << "Monthly Pay of Salaried Employee " << monthlypay << endl;
	}

};
class BuisnessMan :public Person
{
public:
	double annualincome;
public:
	BuisnessMan(double ai, const char* n, int sn, int hn, const char* c) :Person(n, sn, hn, c)
	{
		annualincome = ai;
	}
	void display()
	{
		cout << name << " " << add.StreetNo << " " << add.HouseNo << " " << add.city << endl;
		cout << "Annual Income of Buisness Man " << annualincome << endl;
	}

};
class Mobile
{
public:
	char* model;
	int year;
public:
	int size = 0;
	Mobile()
	{
		year = 0;
		model = new char[size];
	}
	Mobile(int y, const char* m)
	{
		year = y;
		size = strlen(m);
		model = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			model[i] = m[i];
		}
		model[size] = '\0';
	}
	virtual void display()
	{

	}

};
class Nokia :public Mobile
{
public:
	Nokia()
	{

	}
	Nokia(int ye, const char* m) :Mobile(ye, m)
	{
		
	}
    void display()
	{
		cout <<model <<" ";
		cout << year << endl;
		

	}
};
class Oppo :public Mobile
{
public:
	Oppo()
	{

	}
	Oppo(int ye, const char* m) :Mobile(ye, m)
	{

	}
	void display()
	{
		cout <<"Oppo " <<" ";
		cout << model <<" ";
		cout << year << endl;
		
	}
};
class Iphone :public Mobile
{
	
public:
	Iphone()
	{

	}
	Iphone(int ye, const char* m) :Mobile(ye, m)
	{

	}
	void display()
	{
		cout << "Iphone " <<" ";
		cout << model <<" ";
		cout << year << endl;
		
	}

};
class ShopManagement
{
private:
	int userID;
	Person* P2P;
	Mobile* Mob;
public:
	void adduser(int u, Mobile* Mob, Person* P2P)
	{
		userID = u;
		this->Mob = Mob;
		this->P2P = P2P;
	}
    void display()
	{
		cout << "User ID " << userID << endl;
		P2P->display();
		Mob->display();
	}
};
int main()
{
	ShopManagement Users[3];
	Person* p1 = new SalariedEmployee(60000.0, "Ahmad Shan Ali", 12, 39, "Islamabad");
	Mobile* nokia = new Nokia(2017, "Nokia 3310");
	Person* p2 = new BuisnessMan(900000, "Muhammad Mansoor", 25, 46, "Quetta");
	Mobile* oppo = new Oppo(222, "R11s Plus");
	Person* p3 = new SalariedEmployee(400000, "Ali", 22, 1023, "Quetta");
	Mobile* iphone = new Iphone(2021, "13 Pro Max");
	Users[0].adduser(1, nokia, p1);
	Users[1].adduser(2, oppo, p2);

	Users[2].adduser(3, iphone, p3);
	for (int i = 0; i < 3; i++)
	{
		Users[i].display();
	}
	cout << "\n\n";
	return 0;
}