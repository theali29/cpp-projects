#include <iostream>
using namespace std;
template <class T>
double average(T elements[], int size)
{
	double sum = 0;
	for (int i = 0; i < size; i++) 
	{
		sum=sum+elements[i];
	}
	sum = sum / size;
	return sum;
}
int main() {
	
	int integers[5] = { 1, 2, 1, 4, 5 };
	double doubles[4] = { 5.1, 5.5, 2.9, 1.7};
	long longs[5] = { 2147483, 456764, 132684, 4445,78754 };
	char chars[3] = { 'a', 'l', 'i' };


	cout << "Average of integers: " << average<int>(integers, 5) << endl;
cout << "Average of doubles: " << average<double>(doubles, 4) << endl;
	cout << "Average of long: " << average<long>(longs, 5) << endl;
	cout << "Average of chars: " << average<char>(chars, 3) << endl;

	system("pause");
}