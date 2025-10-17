#include"Queue.h"
int func(int s[], int san[])
{
	Queue<int>obj;
	int value=0;
	int counter = 0;
	int top=0;
	for (int i = 0; i < 4; i++)
	{
		value = s[i];
		obj.enque(value);

	}
	while (!obj.isempty() && counter < obj.size())
	{
		if (san[top] == obj.top())
		{
			counter = 0;
			++top;
			obj.deque();
		}
		else
		{
			++counter;
			obj.enque(obj.Front());
		}
	}
	return counter;
}
int main()
{
	Queue<int>q1;
	int stu[4], san[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> stu[i];
		
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> san[i];

	}
	cout << "Input: students[";
	for (int i = 0; i < 4; i++)
	{
		cout<< stu[i]<<",";

	}
	cout << "] Sandwiches[";
	for (int i = 0; i < 4; i++)
	{
		cout << san[i] << ",";

	}
	cout << "]";
	int check=func(stu, san);
	cout << check << endl;;
	q1.printqueue();
	

	system("pause");
	return 0;
}