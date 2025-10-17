#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
	char* name;
	int age;
	int size = 0;
public:
	Person()
	{
	
		name = nullptr;
		name = new char[size];
		age = 0;
	}
	Person(const char*n,int a)
	{
		size = strlen(n);
		name = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			name[i] = n[i];
		}
		name[size] = '\0';
		age = a;
	}
	void setname()
	{
		
		char* n1 = new char[100];
		cout << "Enter a name " << endl;
		cin.getline(n1, 100);
		size = strlen(n1);
		name = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			name[i] = n1[i];
		}
		name[size] = '\0';
		

	}
	char getname()
	{
		return *name;
	}
	void setage()
	{
		int a1;
		cout << "Enter an age " << endl;
		cin >> a1;
		if (a1 > 0)
		{
			age = a1;
		}
	}
	int getage()
	{
		return age;
	}
	void pdisplay()
	{
		cout << "Name " << name << endl;
		cout << "Age " << age << endl;
	}
	
};
class Employee :public Person
{
private:
	double salary;
	int EmployeeId;
public:
	Employee()
	{
		salary = 0.0;
		EmployeeId = 0;
	}
	Employee(double s,int e)
	{

		salary = s;
		EmployeeId = e;
	}
	void setsalary()
	{
		double s1;
		cout << "Enter salary of employee" << endl;
		cin >> s1;
		if (s1 > 0)
		{
			salary = s1;
		}

	}
	double getsalary()
	{
		return salary;
	}
	void setID()
	{
		int ID;
		cout << "Enter an employee ID " << endl;
		cin >> ID;
		if (ID > 0)
		{
			EmployeeId = ID;
		}
	}
	int getID()
	{
		return EmployeeId;
	}
	void edisplay()
	{
		cout << "Salary " << salary << endl;
		cout << "Employee ID " << EmployeeId << endl;
	}
};
class Baseballplayer :public Person
{
private:
	double battingAverage;
	int totalruns;
public:
	Baseballplayer()
	{
		battingAverage = 0.0;
		totalruns = 0;
	}
	Baseballplayer(double ba,int tr)
	{
		battingAverage = ba;
		totalruns =tr;
	}
	void bavergae()
	{
		double ba1;
		cout << "Enter Batting Average " << endl;
		cin >> ba1;
		if (ba1 > 0)
		{
			battingAverage = ba1;
		}
	}
	double getbaverage()
	{
		return battingAverage;
	}
	void setruns()
	{
		int tr1;
		cout << "Enter Total Runs " << endl;
		cin >> tr1;
		if (tr1 > 0)
		{
			totalruns = tr1;
		}
	}
	int getruns()
	{
		return totalruns;
	}
	void bdisplay()
	{
		cout << "Batting Average " << battingAverage << endl;
		cout << "Total Runs " << totalruns << endl;
	}
};
int main()
{
	Baseballplayer bp1;
	bp1.setname();
	bp1.setage();
	bp1.pdisplay();
	bp1.bavergae();
	bp1.setruns();
	bp1.bdisplay();
	Employee e;
	e.setname();
	e.setage();
	e.pdisplay();
	e.setID();
	e.setsalary();
	e.edisplay();
	
}