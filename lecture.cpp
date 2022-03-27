#include<iostream>
#include<string>
using namespace std;
class book
{
protected:
	char* name;
	int isbn;
public:
	int size = 0;
	book(const char* n, int i)
	{
		size = strlen(n);
		name = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			name[i] = n[i];
		}
		name[size] = '\0';
		isbn = i;
	}
	virtual void display() = 0;
	void operator=(book& c)
	{
		size = c.size;
		name = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			name[i] = c.name[i];
		}
		name[size] = '\0';
	}
	~book()
	{
		delete[]name;
		name = nullptr;
	}
};
class section :public book
{
	int pages;
public:
	section(const char* n1, int is, int p) :book(n1, is)
	{
		pages = p;
	}
	void display()
	{
		cout << "Name of the Book:" << name << endl;
		cout << "ISBN of the Book:" << isbn << endl;
		cout << "Pages of the Book:" << pages << endl;
	}

};
class divison :public book
{
	float len;
public:
	divison(const char* n1, int is, float l) :book(n1, is)
	{
		len = l;
	}
	void display()
	{
		cout << "Name of the Book:" << name << endl;
		cout << "ISBN of the Book:" << isbn << endl;
		cout << "Len of the Book:" << len << endl;
	}
};
int main()
{
	const int size = 100;
	char* alpha = new char[size + 1];
	int Ref, page;
	float length;
	cout << "Enter a name of the book " << endl;
	cin.getline(alpha, size);
	cout << "Enter ISBN of the book " << endl;
	cin >> Ref;
	cout << "Enter Pages of the book " << endl;
	cin >> page;
	section s1(alpha, Ref, page);


	cout << "Enter ISBN of the book " << endl;
	cin >> Ref;
	cout << "Enter Length of the book " << endl;
	cin >> length;

	divison d1("Good life", Ref, length);
	book* b1[2];
	b1[0] = &s1;
	b1[1] = &d1;
	b1[0]->display();
	b1[1]->display();
}