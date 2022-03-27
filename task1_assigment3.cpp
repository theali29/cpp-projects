#include<iostream>
using namespace std;
class Marks
{
	int rollno;
	char* name;
	int marks;
public:
	int size = 0;
	Marks()
	{
		name = new char[size];
		rollno = 0;
		marks = 0;

	}
	Marks(const char* n, int r, int m)
	{
		size = strlen(n);
		name = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			name[i] = n[i];
		}
		name[size] = '\0';
		rollno = r;
		marks = m;
	}
	void setname(const char*n)
	{
		size = strlen(n);
		name = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			name[i] = n[i];
		}
		name[size] = '\0';
	}
	char getname()
	{
		return *name;
	}
	void setroll(int r)
	{
		rollno = r;
	}
	int getroll()
	{
		return rollno;
	}
	void display()
	{
		cout << "Name:" << name <<endl;
		cout << "Roll Number:" << rollno << endl;

	}
};
class physics :public Marks
{
	int pmarks;
public:
	physics()
	{
		pmarks = 0;
	}
	physics(int m1)
	{
		pmarks = m1;
	}
	void setphy(int phym)
	{
		pmarks = phym;

	}
	int getphy()
	{
		return pmarks;
	}

};
class chemistry :public Marks
{
	int cmarks;
public:
chemistry(int cm)
	{
		cmarks = cm;
	}
	void setchem(int cmark)
	{
		
		cmarks = cmark;
	}
	int getchem()
	{
		return cmarks;
	}
	
};
class maths :public Marks
{
	int mmarks;
public:
	maths(int m)
	{
		mmarks = m;
	}
	void setmaths(int mmark)
	{
		
		mmarks = mmark;

	}
	int getmaths()
	{
		return mmarks;
	}
	
};

int main()
{
	int  num = 0;
	cout << "Enter Total number of students " << endl;
	cin >> num;
	Marks* m=new Marks[num];
	char* name = new char[20];
	int roll;
	int phy;
	int chem;
	int math;
	int total[100];
	for (int i = 0; i < num; i++)
	{
		cout << "Student " << (i + 1) << endl;
		cout << "Enter the Student name:" << endl; 
		cin >> name;
		cout << "Enter the Student Roll number:" << endl;
		cin >> roll;
        m[i].setname(name);
		m[i].setroll(roll);
		cout << "Enter the Student Physics marks:" << endl;
		cin >> phy;
		cout << "Enter the Student Chemistry marks:" << endl;
		cin >> chem;
		cout << "Enter the Student Mathematics marks:" << endl;
		cin >> math;
		physics p1(phy);
		chemistry c1(chem);
		maths m1(math);
		int first = p1.getphy();
		int second = c1.getchem();
		int third = m1.getmaths();
		
		total[i] = first + second + third;
		
	}
	for (int i = 0; i < num; i++)
	{
		cout << "Student:" << (i + 1) << endl;
		m[i].display();
		cout << "Total  marks:" << total[i] << endl;
	}
	double average = 0.0;
	int totalSum=0;
	for (int i = 0; i < num; i++) {
		totalSum += total[i];
		average = totalSum / num;
	}
	cout << "Total marks of the class is:" << totalSum << endl;
	cout<<"The average marks of the class is :" << average << endl;
}
