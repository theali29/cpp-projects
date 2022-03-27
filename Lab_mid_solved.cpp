//Mohammad Ali
//OOP Midterm  

#include<iostream>
#include<string>
using namespace std;
class IntegerList
{
private:
	int size;
	int* arr;

public:
	IntegerList()
	{

		size = 100;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}
	IntegerList(int s)
	{
		size = s;
		arr = new int[size + 1];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}

	}
	IntegerList(IntegerList& cs, int s1, int s2)
	{

		int k = 0;
		arr = new int[100];
		size = 0;
		for (int i = s1-1; i <= s2-1; i++)
		{
			if (i <= s1-1)

				arr[k++] = cs.arr[i];
			else
				arr[k++] = cs.arr[i];
		}
		arr[k] = 0;
	}

	IntegerList& operator+(IntegerList& as)
	{
		int* temp = new int[size + as.size + 1];
		int j = 0; 
		for (int i = 0; i < size; i++)
		{
			temp[j] = arr[i];
			j++;
		}
		for (int i = 0; i < as.size; i++)
		{
			temp[j] = as.arr[i];
			j++;
		}
		size = size + as.size;
		delete[]arr;
		arr = new int[size + 1];
		for (int i = 0; i < size; i++)
		{
			arr[i] = temp[i];
		}
		return *this;
	}

	bool operator==(IntegerList& op)
	{
		bool flag = 1;
		if (size == op.size)
		{
			for (int i = 0; i < size; i++)
			{
				if (arr[i] != op.arr[i])
				{
					flag = 0;
				}

			}
		}
		else
		{
			flag = 0;
		}
		return flag;
	}
	void operator=(IntegerList& ps)
	{
		size = ps.size;
		arr = new int[size + 1];
		for (int i = 0; i < size; i++)
		{
			arr[i] = ps.arr[i];
		}
	}
	void insert(int i)
	{
		static int size = 0;
		if (arr[0] != 0)
		{
			this->arr[size++] = i;

		}
		else
		{
			size = size - size;
			this->arr[size++] = i;
        }

	}
	int getCount() const
	{
		
		return size;
	}

	 
	/*void setarr()
	{
		int* a = new int[size + 1];
		cout << "Enter an array " << endl;
		for (int i = 0; i < size; i++)
		{
			cin >> a[i];
		}

		arr = new int[size + 1];
		for (int i = 0; i < size; i++)
		{
			arr[i] = a[i];
		}

	}
	/*int getarr()
	{
		return *arr;
	}*/
	/*void setsize()
	{
		int ns;
		size = ns;

	}
	int getsize()
	{
		return size;
	}*/
	IntegerList operator ++ ()
	{
		IntegerList temp;
		for (int i = 0; i < size; i++)
		{
			temp.arr[i] = ++arr[i];
		}
		return temp;
	}
	IntegerList operator -- ()
	{
		IntegerList temp;
		for (int i = 0; i < size; i++)
		{
			temp.arr[i] = --arr[i];
		}
		return temp;
	}
	IntegerList operator ++ (int)
	{
		IntegerList temp;
		for (int i = 0;arr[i]!=0; i++)
		{
			temp.arr[i] = arr[i]+1;
		}
		return temp;
	}
	IntegerList operator -- (int)
	{
		IntegerList temp;
		for (int i = 0; arr[i] != 0; i++)
		{
			temp.arr[i] = arr[i]-1;
		}
		return temp;
	}
	friend IntegerList print(const IntegerList& obj)
	{

		for (int i = 0; obj.arr[i] != 0; i++)
		{
			cout << obj.arr[i] << " ";
		}

		cout << endl;
		return obj;
	}
	void clear()
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = NULL;
		}

	}
	/*~IntegerList()
	{
		delete[]arr;
		arr = nullptr;
	}*/

};
;


int main()
{
	IntegerList list1;//making empty default IntegerList of 100 size
	int number = 12;
	int i = 1;
	while (i <= number)
	{
		list1.insert(i);//inserting elements into list1 by incrementing its index like 0,1,2,3,4 and so on For eg. 1st time insertion will insert at index 0, then index 1 and so on
		i++;
	}
	cout << "list1\n";
	print(list1);
	cout << "The number of elements in list1 = " << list1.getCount() << endl;

	IntegerList list2(list1, 2, 9);//should copy the elements of list1 from position 2 to 9
	cout << "list2 is a copy of list1 from position 2 to 9\n";
	print(list2);
	cout << "The number of elements in list2 = " << list2.getCount() << endl;

	IntegerList list3;
	cout << "list3 is a constant IntegerList\n";
	cout << "The number of elements in list3 = " << list3.getCount() << endl;


	list1.clear();//should set the values of list1 to zeros and its count to zero
	cout << "After clearing list1\n";
	print(list1);

	IntegerList list4(10);//should make an empty IntegerList of size 10(passed as a parameter)
	cout << "list4 is an empty IntegerList of size 10\n";
	print(list4);

	list4.insert(55);//inserting elements into list4
	list4.insert(56);//inserting elements into list4
	list4.insert(57);//inserting elements into list4
	list4.insert(58);//inserting elements into list4
	cout << "After inserting elements in list4\n";
	print(list4);

	IntegerList list5;
	list5 = list2 + list4; //list5 should have both the elements of list2 and list4
	cout << "list5 contains both the elements of list2 and list4\n";
	print(list5);
	//list5[0] = list5[0] + 1;//but it should give compile time error if list5 is constant For eg: const IntegerList list5
	//cout << "After adding 1 to the elmenent at 0 index of list5\n";
	//print(list5);

	cout << "print(list5++);\n";
	print(list5++);//post-increment

	cout << "print(++list5)\n";
	print(++list5);//pre-increment
	cout << "print(--list5)\n";
	print(--list5);//pre-decrement
	cout << "print(list5--)\n";
	print(list5--);//post-decrement

	cout << "list6 is a copy of list5\n";
	IntegerList list6 = list5;//list6 is a copy of list5
	print(list6);


	cout << "print(list5++)\n";
	/*print(list5++);*/

	cout << "Comparing list5 and list6 are equal or not?\n";
	if (list6 == list5) //comparison of two IntegerLists to compare all the elements of IntegerLists
	{
		cout << "As you can see Both the IntegerLists list5 and list6 are equal\n";
		cout << "list5: ";
		print(list5);
		cout << "list6: ";
		print(list6);
	}
	else
	{
		cout << "As you can see Both the IntegerLists list5 and list6 are not equal\n";
		cout << "list5: ";
		print(list5);
		cout << "list6: ";
		print(list6);
	}

	/*cout << "list4 after assignment: ";
	(list4 = list5) = list6;*/
	print(list4);

	return 0;
}