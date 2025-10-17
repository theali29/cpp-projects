#include<iostream>
using namespace std;
class Distance
{
private:
	int feet;
	int inches;
public:
	Distance()
	{
		feet = 0;
		inches = 0;
	}
	Distance(int f,int i)
	{
		feet =f;
		inches = i;
	}
	Distance& operator-(const Distance& sd)
	{
		Distance temp;
		if (feet < sd.feet||inches<sd.inches)
		{
		cout << "Negative distances are not allowed " << endl;
		}
		else
		{
			temp.feet = feet - sd.feet;
			temp.inches = inches - sd.inches;

		}
		return temp;
	}
	void display()
	{
		cout <<"Feet: " << feet <<" Inches:"  << inches << endl;
	}
};
int main()
{
	Distance d3;
	 Distance d1(13, 5);
	 Distance d2(12, 2);
	 d3 = d1 - d2;
	 d3.display();
	 system("pause");
	 return 0;
}

