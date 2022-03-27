#include<iostream>
#include<string>
using namespace std;
template<class t>
class stack
{
	t a;

public:
	stack(t adc)
	{
		a = adc;
	}
	void push(t a1)
	{
		a = a1;
	}
	t pop()
	{
		return a;
	}
	void display()
	{
		cout << a << endl;
	}

};
int main()
{
	stack<int> obj(3);
	obj.push(3);
	obj.push(3);
	obj.push(3);
	obj.push(3);
	obj.display();
	cout << obj.pop();
	obj.display();
	cout << "---------------" << endl;
	stack<char> obj1('a');
	obj1.push('a');
	obj1.push('a');
	obj1.push('a');
	obj1.push('a');
	obj1.display();
	cout << obj1.pop();
	obj1.display();
	cout << "---------------" << endl;
	stack<double> obj2(4.6);
	obj2.push(4.6);
	obj2.display();
	cout << obj2.pop();
	obj2.display();
	cout << "---------------" << endl;
	stack <string> obj3("3");
	obj3.push("3");
	obj3.push("3");
	obj3.push("3");
	obj3.push("3");
	obj3.display();
	cout << obj3.pop();
	obj3.display();

}
