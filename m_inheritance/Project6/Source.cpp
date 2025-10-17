#include<iostream>
#include<string>
using namespace std;
class address
{
protected:
	int street=0, code=0;
	char* city;
	int size = 0;
	char* house;
public:
	void setcity(const char*c)
	{
		size = strlen(c);
		city = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			city[i] = c[i];
		}
		city[size] = '\0';
	}
	char getcity()
	{
		return *city;
	}
	void setstreet(int s)
	{
		street = s;
	}
	char getstreet()
	{
		return street;
	}
	void setcode(int c)
	{
	code = c;
	}
	char getcode()
	{
		return code;
	}
	void sethouse(const char* h)
	{
		size = strlen(h);
		house = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			house[i] = h[i];
		}
		house[size] = '\0';
	}
	char gethouse()
	{
		return *house;
	}
	void display()
	{
		cout << "Street:" << street << endl;
		cout << "House No:" << house << endl;
		cout << "City:" << city << endl;
		cout << "Code:" << code << endl;
	}
};
class Person :public address
{
protected:
	char* address;

public:
	Person()
	{
		address = new char[size];

	}
	void setaddress(const char*ad)
	{
		size = strlen(ad);
		address = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			address[i] = ad[i];
		}
		address[size] = '\0';
	}
	char getaddress()
	{
		return *address;
	}

	void pdisplay()
	{
		cout << "Address:" << address << endl;
	}
};
int main()
{
	Person p1;
	p1.setstreet(21);
	p1.sethouse("155-C");
	p1.setcity("Lahore");
	p1.setcode(54000);
	
	p1.display();

	p1.setaddress("New York,USA,10001");
	
	p1.pdisplay();
}