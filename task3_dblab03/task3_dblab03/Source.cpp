#include"student.h"
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
void search(Student* s1, int size);
void updateCGPA(Student* s1, int size);

int main()
{
	int i = 0, size = 5;
	string line;
	string input;
	Student* s1;

	ifstream fin;
	ofstream temp("temp.csv");

	fin.open("data3.csv");
	s1 = new Student[5];

	while (getline(fin, line))
	{
		stringstream ss(line);
		getline(ss, input, ',');
		s1[i].setreg(input);
		getline(ss, input, ',');
		s1[i].setname(input);
		getline(ss, input, ',');
		s1[i].setprogram(input);
		getline(ss, input, ',');
		s1[i].setcgpa(input);
		getline(ss, input, ',');
		s1[i].setcontact(input);
		i++;

	}
	/*search(s1, size);*/
	updateCGPA(s1,size);
	fin.close();
	temp.close();
	remove("data3.csv");
	int var = rename("temp.csv", "data3.csv");
	if (var == 0)
	{
		cout << "changed";
	}
	else
	{
		cout << "not changed " << endl;
	}
	system("pause");
	return 0;


}
void updateCGPA(Student* s1, int size)
{
	string ureg;
	string ucgpa;
	ofstream temp;
	ifstream fin("data3.csv");
	temp.open("temp.csv", ios::out);

	cout << "Enter a reg no of a student which you want want to update CGPA ";
	cin >> ureg;
	for (int i = 0; i < size; i++)
	{
		if (ureg == s1[i].getreg())
		{
			cout << "Enter a new CGPA ";
			cin >> ucgpa;
			if (ucgpa != s1[i].getcgpa())
			{
				s1[i].setcgpa(ucgpa);
				
			}
        }
		
	}

	for (int i = 0; i < size; i++)
	{

		
		temp << s1[i].getreg() << "," << s1[i].getname() << "," << s1[i].getprogram() << "," << s1[i].getcgpa() << "," << s1[i].getcontact() << endl;

	}
	
	
}
//void search(Student* s1, int size)
//{
//	string ireg;
//	cout << "Enter a registration number";
//	cin >> ireg;
//
//	for (int i = 0; i < size; i++)
//	{
//
//		if (ireg == s1[i].getreg())
//		{
//			s1[i].display();
//		}
//	}
//}