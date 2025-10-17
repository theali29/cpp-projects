//Mohammad Ali
//Operator Overloading

#include<iostream>
#include<string>
using  namespace std;
class mystring
{
	char* ptr;
	int size;
public:
	mystring()
	{
		ptr = new char[size];
		size = 0;

	}
	mystring(const char* s)
	{
		size = strlen(s);
		ptr = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			ptr[i] = s[i];
		}
		ptr[size] = { '\0' };
	}
	mystring(const mystring& MS)
	{
		size = MS.size;
		ptr = new char[size + 1];
		for (int i = 0; i < MS.size; i++)
		{
			ptr[i] = MS.ptr[i];
		}
		ptr[size] = { '\0' };

	}

	void setstring(const char* p)
	{


		size = strlen(p);
		ptr = new char[size + 1];

		for (int i = 0; i < size; i++)
		{
			ptr[i] = p[i];
		}

		ptr[size] = { '\0' };

	}
	void Print()
	{
		cout << "My string:" << ptr << endl;
	}

	bool operator==(mystring& cs)
	{
		bool flag = 1;
		if (size==cs.size)
		{
			for (int i = 0; i < cs.size; i++) 
			{
				
				if (ptr[i] != cs.ptr[i]) 
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
	mystring& operator +(const mystring& st)
	{

		char* temp = new char[size + st.size + 1];
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			temp[j] = ptr[i];
			j++;
		}
		temp[size] = '\0';
		for (int i = 0; i < st.size; i++)
		{
			temp[j] = st.ptr[i];
			j++;
		}

		size = size + st.size;
		temp[size] = '\0';

		delete[]ptr;
		ptr = new char[size + 1];

		for (int i = 0; i < size; i++)
		{
			ptr[i] = temp[i];
		}
		ptr[size] = '\0';
		delete[] temp;


		return *this;

	}


	mystring& operator=(const mystring& c)
	{

		if (this == &c)
		{
			return *this;
		}
		if (ptr != NULL)
		{
			delete[] ptr;
		}
		size = c.size;
		ptr = new char[size + 1];
		for (int i = 0; i < size; i++)
		{

			ptr[i] = c.ptr[i];
		}
		ptr[size] = { '\0' };

		return *this;
	}



	~mystring()
	{
		delete[]ptr;
		ptr = nullptr;
	}
};
int main()
{
	mystring s;
	mystring s1("Ali");
	mystring s2;
	s1.Print();
	s2.setstring("Ali is");
	s2.Print();
	
	cout << "Comparison Operators " << endl;
	if (s1 == s2)
	{
		cout << "They are both equal " << endl;
	}
	else
	{
		cout << "They are not equal " << endl;
	}
	cout << "Binary Operator Overloading " << endl;
	s = s1 + s2;
	s.Print();
	cout << "Assignment Operator overloading " << endl;
	s1 = s2;
	s1.Print();

	system("pause");
	return 0;

}
