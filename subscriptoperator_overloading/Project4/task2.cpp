#include<iostream>
using namespace std;
class myarray
{
private:
	int *arr;
	int size = 0;
public:
	myarray()
    {
		arr = NULL;
		size = 0;
    }
	myarray(int* a, int s)
	{
		size = s;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = a[i];
		}
		
	}
	int &operator[](const int index)
	{
		if (index>=size)
		{
			cout << "Index array is out of size " << endl;
			exit(0);
		}
		return arr[index];
		
	}
	void display()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
int	d[] = { 1,2,3,4,5 };
myarray d1(d, 5);
d1[0]=5;
d1[1] = 10;
d1[2] = 15;
d1[3] = 20;
d1[4] = 25;
d1.display();
d1[5] = 30;
system("pause");
return 0;

}