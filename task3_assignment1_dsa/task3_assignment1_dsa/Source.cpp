#include"MyStack.h"

int main()
{
	MyStack <char> s1;
	s1.push('D');
	s1.push('C');
	s1.push('B');
	s1.push('A');
	cout << s1.top() << endl;
	s1.pop();
	cout << s1.top() << endl;
	s1.pop();
	cout << s1.top() << endl;
	s1.pop();
	cout << s1.top() << endl;

	return 0;
}
