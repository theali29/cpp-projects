# define SIZE 5
#include"stackADT.h"
#include"stack.h"
int main()
{
	StackADT<int>* ptr;
	Stack<int>pt;
	pt.push(5);
	pt.push(1);
	cout << pt.size() << endl;
	pt.pop();
	if (pt.pop() == -1)
	{
		cout << "Stack is empty" << endl;
	}
	pt.pop();
	if (pt.pop() == -1)
	{
		cout << "Stack is empty" << endl;
	}
	pt.pop();
	if (pt.pop() == -1)
	{
		cout << "Stack is empty" << endl;
	}
	ptr = &pt;
}

