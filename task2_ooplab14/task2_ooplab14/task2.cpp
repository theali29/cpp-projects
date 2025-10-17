#include<iostream>
using namespace std;
class person
{
	
public:
	char* name;
	int age;
	int size = 0;
	person()
	{
		name = new char[size];
		age = 0;
	}
	person(const char* n, int a)
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
	void display()
	{
		cout << name << " " << age << endl;
	}
};
class employee
{
public:

	char* name;
	float wage;
	int size = 0;
	employee()
	{
		name = new char[size];
		wage = 0.0;
	}
	employee(const char* n, float w)
	{
		size = strlen(n);
		name = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			name[i] = n[i];
		}
		name[size] = '\0';
		wage=w;
	}
	void display()
	{
		cout << name << " " << wage << endl;
	}
};
class teacher
{
public:
	
	person p1;
    person p2;
	employee e1, e2;
	



};
int main()
{
	teacher t1,t2;
	t1.p1=person("Ali",22);
	t1.p2 = person("Fahad", 20);
	t1.p1.display();
	t1.p2.display();
	t2.e1 = employee("Farrukh", 56834.45);
	t2.e2= employee("Ramna", 43543.23);
	t2.e1.display();
	t2.e2.display();
}