#include<iostream>
using namespace std;
class heap
{
public:
	int size = 0;
	int arr[100];
	int n = 5;
public:
	void insertion_heapmax(int val)
	{
		size = size + 1;
		int index = size;
		arr[index] = val;
		while (index > 1)
		{
			int parent = index / 2;
			if (arr[index] > arr[parent])
			{
				swap(arr[index], arr[parent]);
				index = parent;
			}
			else
			{
				return;
			}
		}
	}

	void heapsortia()
	{
		int size = n;
		while (size > 1)
		{
			swap(arr[size], arr[1]);
			size--;

			heapify_heapmax(arr, size, 1);
		}
	}
	void heapsortid()
	{
		int size = n;
		while (size > 1)
		{
			swap(arr[size], arr[1]);
			size--;

			heapify_heapmin(arr, size, 1);
		}
	}
	void insertion_heapmin(int val)
	{
		size = size + 1;
		int index = size;
		arr[size] = val;

		while (index > 1)
		{
			int parent = index / 2;
			if (arr[parent] > arr[index])
			{
				swap(arr[parent], arr[index]);
				index = parent;
			}
			else
			{
				return;
			}
		}
	}
	void buildheap_(int arr[], int n)
	{
		this->n = n;
		for (int a = n / 2; a >= 1; a--)
		{
			heapify_heapmax(arr, n, a);
		}
	}
	void heapify_heapmax(int arr[], int n, int i)
	{
		int largest = i;
		int left = 2 * i;
		int right = 2 * i + 1;

		if (left <= n && arr[largest] < arr[left])
			largest = left;

		if (right <= n && arr[largest] < arr[right])
			largest = right;

		if (largest != i)
		{
			swap(arr[largest], arr[i]);
			heapify_heapmax(arr, n, largest);
		}
	}
	
	void heapify_heapmin(int arr[], int n, int i)
	{
		int largest = i;
		int left = 2 * i;
		int right = 2 * i + 1;

		if (left <= n && arr[largest] > arr[left])
			largest = left;

		if (right <= n && arr[largest] > arr[right])
			largest = right;

		if (largest != i)
		{
			swap(arr[largest], arr[i]);
			heapify_heapmin(arr, n, largest);
		}
	}
	void deleteroot()
	{
		int lastelement = arr[n];
		arr[1] = lastelement;
		n= n - 1;
	    heapify_heapmax(arr, n, 1);
    }
	void print()
	{
		for (int a = 1; a <= n; a++)
		{
			cout << arr[a] << " ";
		}
		cout << endl;
	}

};
int main()
{
	heap s1;
	s1.insertion_heapmax(4);
	s1.insertion_heapmax(5);
	s1.insertion_heapmax(10);
	s1.insertion_heapmax(7);
	s1.insertion_heapmax(77);
	s1.print();
	int n = 5;
	s1.deleteroot();
	cout << "After deleting" << endl;
	s1.print();
	 n = 6;
	heap s2;
	int arr[100] = { -1,5,6,3,7,8 };
	s2.buildheap_(arr, n);

	for (int a = 0; a < n; a++)
	{
	
		cout << arr[a] << " ";
	}
	cout << endl;


	s1.heapsortia();
	s1.print();
	n = 5;
	
	s1.heapsortid();
	s1.print();

	heap s23;
	int nn = 7;
	int arr2[100] = { 12,34,2,1,5,4,9};
	s23.buildheap_(arr2, nn);
	s23.heapsortia();
	for (int a = 0; a < nn; a++)
	{

		cout << arr2[a] << " ";
	}
	cout << endl;

}