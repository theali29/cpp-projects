#include<iostream>
using namespace std;
template <class t>
class arithmeticoperations
{
public:
void add(t a, t b)
	{
		cout<< a + b<<endl;
	}
void subtract(t a, t b)
	{
		cout<<a - b<<endl;
	}
	void multiply(t a, t b)
	{
		cout<< a * b<<endl;
	}
	float divide(t a, t b)
	{
		float div = a / b;
		cout << div << endl;
		return div;
		
	}
	/*void display()
	{
		cout << a <<" "<< b << endl;
	}*/
};
int main()
{
	int n1, n2;
	arithmeticoperations<int> hc;
	cout << "Enter first and second integer ";
	cin >> n1 >> n2;
	cout << endl;
	hc.add(n1, n2);
	hc.subtract(n1, n2);
	hc.multiply(n1, n2);
	cout << endl;
	hc.divide(n1, n2);
	float f1, f2;
	arithmeticoperations<float> hcs;
	cout << "Enter first and second integer ";
	cin >> f1 >> f2;
	cout << endl;
	hcs.add(f1, f2);
	hcs.subtract(f1, f2);
	hcs.multiply(f1, f2);
	cout << endl;
	hcs.divide(f1, f2);
	char c1, c2;
	arithmeticoperations<char> hcp;
	cout << "Enter first and second integer ";
	cin >> c1 >> c2;
	cout << endl;
	hcp.add(c1, c2);
	hcp.subtract(c1, c2);
	hcp.multiply(c1, c2);
	cout << endl;
	hcp.divide(c1, c2);
	double d1, d2;
	arithmeticoperations<double> hcd;
	cout << "Enter first and second integer ";
	cin >> d1 >> d2;
	cout << endl;
	hcd.add(d1, d2);
	hcd.subtract(d1, d2);
	hcd.multiply(d1, d2);
	cout << endl;
	hcd.divide(d1, d2);
	/*hc.display();*/

}