#include "student.h"
#include<fstream>
#include<sstream>
Student::Student()
{

	//name = '\0';
	//reg = '\0';
	//program = '\0';
	//cgpa = 0.0;
	//contactno = 0;

}
void Student::setname(string n)
{
	name = n;
}
string Student::getname()
{
	return name;
}

void Student::setreg(string r)
{
	reg = r;
}
string Student::getreg()
{
	return reg;
}

void Student::setprogram(string p)
{
	program = p;
}
string Student::getprogram()
{
	return program;
}

void Student::setcgpa(string cg)
{
	cgpa = cg;
}
string Student::getcgpa()
{
	return cgpa;
}

void Student::setcontact(string c)
{
	contactno = c;
}
string Student::getcontact()
{
	return contactno;
}
void Student::display()
{
	cout << "Name: " << name << endl;
	cout << "Registration No: " << reg << endl;
	cout << "Program " << program << endl;
	cout << "CGPA " << cgpa << endl;
	cout << "Contact No: " << contactno << endl;

}
Student::~Student()
{

}
