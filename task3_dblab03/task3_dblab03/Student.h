#pragma once
#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;
class Student
{
	string name;
	string reg;
	string program;
	string cgpa;
	string contactno;

public:
	Student();
	void setname(string n);
	string getname();
	void setreg(string reg);
	string getreg();
	void setprogram(string pro);
	string getprogram();
	void setcgpa(string cg);
	string getcgpa();
	void setcontact(string c);
	string getcontact();
	void display();

	~Student();
};

