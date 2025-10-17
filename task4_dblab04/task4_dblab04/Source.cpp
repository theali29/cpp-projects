#include"student.h"
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
void deletedata(Student* s1, int sizz);

int main()
{
	int i = 0, size = 5;
	string line;
	string input;
	Student* s1;
	ofstream temp;
	ifstream fin;
	
	fin.open("data4.csv");
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
	deletedata(s1, size);
	fin.close();
	temp.close();
	remove("data4.csv");
     rename("temp.csv", "data4.csv");
	system("pause");
	return 0;


}
void deletedata(Student* s1, int size)
{
	string ireg;
	cout << "Enter a registration no " << endl;
	cin >> ireg;
	ofstream temp;
	ifstream fin("data4.csv");
	temp.open("temp.csv", ios::out);
	for (int i = 0; i < size; i++)
	{
		if (ireg != s1[i].getreg())
		{
		
			temp << s1[i].getreg() << "," << s1[i].getname() << "," << s1[i].getprogram() << "," << s1[i].getcgpa() << "," << s1[i].getcontact() << endl;
		}
	}
}