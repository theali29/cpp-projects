#include "marks.h"
marks::marks()
{
	
}

marks::marks(int a, const char* b, int c)
{
	
	rollnumber = a;
	size = strlen(b);
	name = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		name[i] = b[i];
	}
	name[size] = '\0';
	mark_s = c;
}
void marks::setrollnumber(int a)
{
	rollnumber = a;
}
void marks::setname(char* b)
{
	int size = strlen(b);
	name = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		name[i] = b[i];
	}
	name[size] = '\0';
}
void marks::setmark_s(int a)
{
	mark_s = a;
}
int marks::getrollnumber()
{
	return rollnumber;
}
char* marks::getname()
{
	char* temp;
	int size = strlen(name);
	temp = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = name[i];
	}
	temp[size] = '\0';
	return temp;
}
void marks::display()const
{
	cout << "Name=" << name << endl;
	cout << "Roll Number=" << rollnumber << endl;
	
}

marks::~marks()
{
}