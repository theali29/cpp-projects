#include<iostream>
#include<string>
using namespace std;
class MyString
{
private:
	int size;
	char* ptr;


public:
	int size12 = 0;
	MyString()
	{
		size = 100;
		ptr = NULL;
		ptr = new char[size + 1];

	}
	MyString(int s)
	{
		size = s;
		ptr = new char[size + 1];


	}

	MyString(const MyString& p, int s1, int s2)
	{

		size = strlen(p.ptr);
		size = size - s2;
		ptr = new char[size + 1];
		int k = s1 - 1;
		for (int i = 0; i < size; i++)
		{
			ptr[i] = p.ptr[k];
			k++;
		}
		ptr[size] = '\0';
	}

	


	void add(char a)
	{
		static int size = 0;
		if (ptr[0] != '\0')
		{
			this->ptr[size++] = a;
			
		}
		else
		{
			size = size - size;
			this->ptr[size++] = a;
			
		}
		ptr[size] = '\0';

	}
	int  length()const
	{

		return size;
	}
	void clear()
	{
		for (int i = 0; i < size; i++)
		{
			ptr[i] = '\0';
		}
		ptr[size] = '\0';
	}
	MyString& operator+(const MyString& at)
	{
		size = strlen(ptr);
		char* temp = new char[size + at.size + 1];
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			temp[j] = ptr[i];
			j++;
		}
		for (int i = 0; i < at.size; i++)
		{
			temp[j] = at.ptr[i];
			j++;
		}
		size = size + at.size;
		temp[size] = '\0';
		delete[]ptr;
		ptr = temp;
		return *this;
	}

	/*~MyString()
	{
		delete[]ptr;
		ptr = nullptr;
	}*/
	friend void print(MyString p);
};


void print(MyString p)
{
	cout << p.ptr << endl;
}

int main()
{
	//char ptr[] = { 'a','b','c','d' };

	MyString str1;// make a default string of 100 size 
	str1.add('[');
	str1.add('A');
	str1.add('B');
	str1.add('C');//insert at position 4 or index 3
	str1.add('D');//insert at position 5 or index 4 
	str1.add('E');//insert at position 6 or index 5 
	str1.add('F');//insert at position 7 or index 6 
	str1.add('G');//insert at position 8 or index 7 
	str1.add('h');//insert at position 9 or index 8 
	str1.add('i');//insert at position 10 or index 9 
	str1.add('j');//insert at position 11 or index 10 
	str1.add('k');//insert at position 12 or index 11 
	str1.add('l');//insert at position 13 or index 12 
	str1.add('m');//insert at position 14 or index 13 
	str1.add('n');//insert at position 15 or index 14 
	str1.add('o');//insert at position 16 or index 15
	str1.add('p');//insert at position 17 or index 16 
	str1.add(']');//insert at position 18 or index 17
	cout << "str1\n";
	print(str1);
	cout << "Length of str1 is = " << str1.length() << endl;
	cout << "str2\n";
	MyString str2(str1, 2, 9);//should copy str1 to str2 from position 2 to 9 
	print(str2);
	cout << "Lenghth of str2 is = " << str2.length() << endl;
	cout << "str4\n";
	const MyString str4; //It should accesss all constant functions 
	print(str4);
	cout << "Lenghth of str4 is =" << str4.length() << endl;
	str1.clear();//It should clear the string by placing null char at all indexes and 
	//setting count to zero
	cout << "After clearing str1\n";
	print(str1);
	str1.add('$');
	cout << "After adding $ to str1\n";
	print(str1);
	MyString str3;
	str3 = str1 + str2;//It will concatenate both the strings and assign it to str3 
	cout << "str3\n";
	print(str3);
	MyString str5(5);//should make an empty array of size 5 
	str5.add('a');
	str5.add('B');
	str5.add('c');
	str5.add('D');
	str5.add('e');
	cout << "str5\n";
	print(str5);
	str3 = str3;
	system("pause");
	return 0;
}
