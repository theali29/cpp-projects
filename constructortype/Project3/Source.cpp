//Mohammad Ali
//Calculating Area using Constructors
#include<iostream>
#include<string>
using namespace std;
class area
{
public:
	int length;
	int breadth;
	int result = 0;
	area()    //default constructor
	{
		length = 6;
		breadth = 8;
		
	}
public:
	area(int lengths, int width)  //parametrized constructor
	{
		length = lengths;
		breadth = width;
	}
	int calarea()  //function calling 
	{
		result = length * breadth;
		return result;
	}
	void display() //display function
	{
		cout << "Area is "<<result << endl;
	}
public:
	area(area& k2) //copy constructor
	{
		length = k2.length;
		breadth = k2.breadth;
	}
};
int main()
{
	area k1;
	area k2(2,6);
	area k3(k2);
	k1.calarea();
	cout << "Area of object k1 (default constructor) is" << endl;
	k1.display();
	k2.calarea();
	cout << "Area of object k2 (parameterized  constructor) is" << endl;
	k2.display();

	k3.calarea();
	cout << "Area of object k3 (copy  constructor) is" << endl;
	k3.display();
	
}
