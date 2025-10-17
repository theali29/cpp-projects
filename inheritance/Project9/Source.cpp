#include "marks.h"
#include "math.h"
#include "physics.h"
#include "chemistry.h"
#include<iostream>
using namespace std;
int main()
{
	int num = 0;
	cout << "Enter number of Students" << endl;
	cin >> num;
	marks* m = new marks[num];
	int total[100];
	for (int i = 0; i < num; i++)
	{
		cout << "Student no:" << (i + 1) << endl;
		cout << "Enter the Student name:" << endl;
		char* name = new char[20];
		cin >> name;

		int rollnumber;
		cout << "Enter the Student rollnumber" << endl;
		cin >> rollnumber;
		m[i].setname(name);
		m[i].setrollnumber(rollnumber);
		int phy = 0;
		cout << "Enter Physics marks=" << endl;
		cin >> phy;
		int chy = 0;
		cout << "Enter chemistry marks=" << endl;
		cin >> chy;
		int mat_h = 0;
		cout << "Enter math marks=" << endl;
		cin >> mat_h;
		physics ph(phy);
		chemistry ch(chy);
		math mat(mat_h);
		int first = ph.getbmarks();
		int second = ch.getcmarks();
		int third = mat.getamarks();
		total[i] = first + second + third;
	}
	for (int i = 0; i < num; i++)
	{
		cout << "Student:" << (i + 1) << endl;
		m[i].display();
		cout << "Total  marks:" << total[i] << endl;
	}
	double average = 0.0;
	int totalSum = 0;
	for (int i = 0; i < num; i++) {
		totalSum += total[i];
		average = totalSum / num;
	}
	cout << "Total marks of the class is:" << totalSum << endl;
	cout << "The average marks of the class is :" << average << endl;


	system("pause");
	return 0;
}