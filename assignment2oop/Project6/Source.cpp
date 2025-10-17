#include<iostream>
#include<string>
using namespace std;
class stringdata
{
private:
	char* data;
	int size;
public:

	stringdata()
	{
		data = new char[size];
	    size = 0;
	}
	stringdata(const char* d)
	{
		size = strlen(d);

		data = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			data[i] = d[i];
		}
		data[size] = { '\0' };
	}
		

	
	stringdata(const stringdata &cs)
	{

		size = cs.size;
		data = new char[size + 1];
		for (int i = 0; i < cs.size; i++)
		{
			data[i] = cs.data[i];
		}
		data[size] = { '\0' };

	}
	bool operator<=(const stringdata& obj)
	{
		if (data <= obj.data)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>=(const stringdata& obj)
	{
		if (data >= obj.data)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>(const stringdata& obj)
	{
		if (data > obj.data)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator<(const stringdata& obj)
	{
		if (data < obj.data)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	stringdata &operator+(const stringdata& d)
	{
		stringdata result;

		char* temp = new char[size + d.size+1];
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			temp[j] = data[i];
			j++;
		}
		
		for (int i = 0; i < d.size; i++)
		{
			temp[j] = d.data[i];
			j++;

		}
		
		
		temp[size+d.size] = { '\0' };
		

		delete[] result.data;
		result.data = temp;
		result.size = size+d.size;

		return result;
	}
	
	/*void display()
	{
		cout << data << endl;
	}*/
	bool operator==(const stringdata& t)
	{
		bool flag = 1;
		if (size == t.size)
		{
			for (int i = 0; i < t.size; i++)
			{
				if (data[i] != t.data[i])
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
	bool operator!=(const stringdata& t)
	{
		bool flag = 0;
		if (size == t.size)
		{
			for (int i = 0; i < t.size; i++)
			{
				if (data[i] != t.data[i])
				{
					flag = 1;
				}
			}
		}
		else
		{
			flag = 1;
		}
		return flag;
	}
	stringdata operator+=(const stringdata&as)
	{
		
		char* temp = new char[size + as.size + 1];
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			temp[j] = data[i];
			j++;
		}
		for (int i = 0; i < as.size; i++)
		{
			temp[j] = as.data[i];
			j++;
		}
		size = size + as.size;
		temp[size] = { '\0' };
		delete[]data;
		data = temp;
		

		return *this;

	}
	friend ostream& operator << (ostream& output, const stringdata& f);
	friend istream& operator >> (istream& input, stringdata& f);
	~stringdata()
	{
		//delete[]data;
		///*data = nullptr;*/
	}
};

 istream & operator>>(istream & input, stringdata & f)
{
	
	int size=50;
	char* temp = new char[size];
	input.getline(temp, size);
	f = stringdata(temp);
	delete[] temp;

	return input;
}

ostream& operator<<(ostream& output, const stringdata& f)
{
	
	output << f.data;
	
	return output;
}
int main()
{
	stringdata s;
	stringdata s1;
	stringdata s2;
	cout << "Enter first object " << endl;
	cin >> s1;
	cout << "Enter Second object " << endl;
	cin >> s2;
	
	cout << "Entered Data S1  " << endl;
	cout << s1 << endl;
	cout << "Entered Data S2  " << endl;
	cout << s2 << endl;
	
	cout << "Logical Operator(<=) " << endl;
	if (s1 <= s2)
	{
		cout << "S2 Object is greater than or equal to S1 Object" << endl;
	}
	else
	{
		cout << "S2 Object is not greater than or equal to S1 " << endl;
	}
	cout << "---------------------------------------------------------" << endl;
	cout << "Logical Operator(>=) " << endl;
	if (s1 >= s2)
	{
		cout << "S1 Object is greater than or equal to S2 Object" << endl;
	}
	else
	{
		cout << "S1 Object is not greater than or equal to S2 object " << endl;
	}
	cout << "----------------------------------------------------------" << endl;
	cout << "Logical Operator(>) " << endl;
	if (s1 > s2)
	{
		cout << "S1 Object is greater than  S2 Object" << endl;
	}
	else
	{
		cout << "S1 Object is not greater than S2 object " << endl;
	}
	cout << "----------------------------------------------------------" << endl;
	cout << "Logical Operator(<) " << endl;
	if (s1 < s2)
	{
		cout << "S2 Object is greater than  S1 Object" << endl;
	}
	else
	{
		cout << "S2 Object is not greater than S1 object " << endl;
	}
	cout << "----------------------------------------------------------" << endl;
	cout << "Logical Operator(==)" << endl;
	if (s1 == s2)
	{
		cout << "They are equal" << endl;
	}
	else
	{
		cout << "They are not equal" << endl;
	}
	cout << "----------------------------------------------------------" << endl;
	cout << "Logical Operator(!=)" << endl;
	if (s1 != s2)
	{
		cout << "They are not equal" << endl;
	}
	else
	{
		cout << "They are equal" << endl;
	}
	s = s1 + s2;
	cout << "----------------------------------------------------------" << endl;
	cout << "Binary Operator(+) " << endl;
	/*s.display();*/
	
	cout << s << endl;
	
	cout << "----------------------------------------------------------" << endl;
	cout << "Binary Operator(+=) " << endl;
	s1 += s2;
	cout << s1 << endl;
	/*s1.display();*/
	system("pause");
	return 0;
		
}