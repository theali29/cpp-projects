#include<iostream>
using namespace std;

class Bank
{
private:
	int Branch_Code;
	char* Address;
	char* Name;
	Customer** List_of_Customers;
	Employee** List_of_Employees;
	int current_customers;
	int current_employees;

public:
	Bank()
	{
		this->Address = nullptr;
		this->Branch_Code = 0;
		this->Name = nullptr;
		this->List_of_Customers = new Customer * [100];
		this->List_of_Employees = new Employee * [10];
		this->current_customers = 0;
		this->current_employees = 0;
	}
	void add_customer(char* f, char* l, int a, char* ssn, char* p, char* e, int c_id, char* c_no, int n, float b, int t, int y_or_p)
	{
		//person details
		this->List_of_Customers[this->current_customers]->set_fname(f);
		this->List_of_Customers[this->current_customers]->set_lname(l);
		this->List_of_Customers[this->current_customers]->set_age(a);
		this->List_of_Customers[this->current_customers]->set_ssn(ssn);
		this->List_of_Customers[this->current_customers]->set_phone(p);
		this->List_of_Customers[this->current_customers]->set_email(e);
		//customer details others
		this->List_of_Customers[this->current_customers]->set_cutomerid(c_id);
		this->List_of_Customers[this->current_customers]->set_card_num(c_no);
		//account type and details
		this->List_of_Customers[this->current_customers]->set_account(n, b, t, y_or_p);
		//
		this->current_customers;
	}
	void add_employee(char* f, char* l, int a, char* ssn, char* p, char* e, int e_id, float s)
	{
		//person details
		this->List_of_Employees[this->current_employees]->set_fname(f);
		this->List_of_Employees[this->current_employees]->set_lname(l);
		this->List_of_Employees[this->current_employees]->set_age(a);
		this->List_of_Employees[this->current_employees]->set_ssn(ssn);
		this->List_of_Employees[this->current_employees]->set_phone(p);
		this->List_of_Employees[this->current_employees]->set_email(e);
		//employee other details
		this->List_of_Employees[this->current_employees]->set_emp_id(e_id);
		this->List_of_Employees[this->current_employees]->set_salary(s);
	}
	void Populate_Customer(char filename[])
	{
		fstream fin(filename);
		if (fin.is_open())
		{
			char buf[500];
			fin.getline(buf, 500, '\n');
			while (!fin.eof())
			{
				this->List_of_Customers[this->current_customers] = new Customer;

				int b = 0, b1 = 0, y_or_p = 0;
				float f = 0;
				double s = 0.0;

				//fname
				fin.getline(buf, 100, '\t');
				this->List_of_Customers[this->current_customers]->set_fname(buf);
				//lname
				fin.getline(buf, 100, '\t');
				this->List_of_Customers[this->current_customers]->set_lname(buf);
				//age
				fin >> b;
				this->List_of_Customers[this->current_customers]->set_age(b);
				//ssn
				fin.ignore();
				fin.getline(buf, 100, '\t');
				this->List_of_Customers[this->current_customers]->set_ssn(buf);
				//phone
				fin.getline(buf, 100, '\t');
				this->List_of_Customers[this->current_customers]->set_phone(buf);
				//email
				fin.getline(buf, 100, '\t');
				this->List_of_Customers[this->current_customers]->set_email(buf);
				//customer id
				fin >> b;
				this->List_of_Customers[this->current_customers]->set_cutomerid(b);
				//card number
				fin.ignore();
				fin.getline(buf, 100, '\t');
				this->List_of_Customers[this->current_customers]->set_card_num(buf);
				//acc type
				fin >> b;
				//acc num
				fin >> b1;
				//balance
				fin >> f;
				//y_or_p
				fin >> y_or_p;
				this->List_of_Customers[this->current_customers]->set_account(b1, f, b, y_or_p);
				this->current_customers++;
				fin.ignore();

			}
		}
		fin.close();
	}
	void Populate_Employee(char filename[])
	{
		fstream fin(filename);
		if (fin.is_open())
		{
			char buf[500];
			fin.getline(buf, 500, '\n');
			while (!fin.eof())
			{
				this->List_of_Employees[this->current_employees] = new Employee;

				int b = 0, y_or_p = 0;
				float f = 0;
				double s = 0.0;

				//fname
				fin.getline(buf, 100, '\t');
				this->List_of_Employees[this->current_employees]->set_fname(buf);
				//lname
				fin.getline(buf, 100, '\t');
				this->List_of_Employees[this->current_employees]->set_lname(buf);
				//age
				fin >> b;
				this->List_of_Employees[this->current_employees]->set_age(b);
				//ssn
				fin.ignore();
				fin.getline(buf, 100, '\t');
				this->List_of_Employees[this->current_employees]->set_ssn(buf);
				//phone
				fin.getline(buf, 100, '\t');
				this->List_of_Employees[this->current_employees]->set_phone(buf);
				//email
				fin.getline(buf, 100, '\t');
				this->List_of_Employees[this->current_employees]->set_email(buf);
				//eid
				fin >> b;
				this->List_of_Employees[this->current_employees]->set_emp_id(b);
				//salary
				fin >> f;
				this->List_of_Employees[this->current_employees]->set_salary(f);
				this->current_employees++;

			}
		}
		fin.close();
	}
	void set_code(int c)
	{
		this->Branch_Code = c;
	}
	void set_address(char* add)
	{
		strcopy(this->Address, add);
	}
	void set_name(char* n)
	{
		strcopy(this->Name, n);
	}
	void strcopy(char*& des, char* src)
	{
		int len = 0;
		for (int i = 0; src[i] != '\0'; i++)
		{
			len++;
		}
		des = new char[len + 1];
		for (int i = 0; i < len + 1; i++)
		{
			des[i] = src[i];
		}
	}
	void Display_Customer_by_Id(int id)
	{
		for (int i = 0; i < this->current_customers; i++)
		{
			if (this->List_of_Customers[i]->get_customer_id() == id)
			{
				List_of_Customers[i]->Display();
			}
		}
	}
	void Display_Employee_by_Id(int id)
	{
		for (int i = 0; i < this->current_employees; i++)
		{
			if (this->List_of_Employees[i]->get_employee_id() == id)
			{
				List_of_Employees[i]->Display();
			}
		}
	}
	void Display_Customers()
	{
		cout << "\n\n		**************************  Displaying All Customer Details  *******************************" << endl;
		for (int i = 0; i < this->current_customers; i++)
		{
			cout << "\n|----------------------------  Customer # " << i + 1 << "  -----------------------------|" << endl;
			this->List_of_Customers[i]->Display();
		}
	}
	void Display_Employees()
	{
		cout << "\n\n		**************************  Displaying All Customer Details  *******************************" << endl;
		for (int i = 0; i < this->current_employees; i++)
		{
			cout << "\n|----------------------------  Employee # " << i + 1 << "  -----------------------------|" << endl;
			this->List_of_Employees[i]->Display();
		}
	}
	void Withdraw_Amount(int customer_id, float amount)
	{
		for (int i = 0; i < this->current_customers; i++)
		{
			if (List_of_Customers[i]->get_customer_id() == customer_id)
			{
				List_of_Customers[i]->Withdraw_Amount(amount);
				return;
			}
		}
		cout << "Customer not Found !!!" << endl;
	}
	void Deposit_Amount(int customer_id, float amount)
	{
		for (int i = 0; i < this->current_customers; i++)
		{
			if (List_of_Customers[i]->get_customer_id() == customer_id)
			{
				List_of_Customers[i]->Deposit_Amount(amount);
				return;
			}
		}
		cout << "Customer not Found !!!" << endl;
	}
};

class Account
{
protected:
	int Account_Number;
	float Balance;
	int Account_Type;

public:
	Account()
	{
		this->Account_Number = 0;
		this->Balance = 0.0;
		this->Account_Type = 0;

	}
	Account(int acc_n, float b, int acc_t)
	{
		this->Account_Number = acc_n;
		this->Balance = b;
		this->Account_Type = acc_t;
	}
	void Deposit_Amount(float d)
	{
		this->Balance = this->Balance - d;
		cout << "Amount Has Successfully Deposited in Customer Account !" << endl;
	}
	void Withdraw_Amount(float d)
	{
		if (this->Balance >= d)
		{
			this->Balance = this->Balance - d;
			cout << "Amount Withdrawal has Done Successfully !!!" << endl;
			return;
		}
		cout << "Funds are not enough for Withdrawal... Try Again !!!" << endl;
	}
	void Set_Account_Num(int acc_n)
	{
		this->Account_Number = acc_n;
	}
	void strcopy(char*& des, char* src)
	{
		int len = 0;
		for (int i = 0; src[i] != '\0'; i++)
		{
			len++;
		}
		des = new char[len + 1];
		for (int i = 0; i < len + 1; i++)
		{
			des[i] = src[i];
		}
	}
	void Set_Balance(float balan)
	{
		this->Balance = balan;
	}
	void Set_Account_Type(int acc_type)
	{
		this->Account_Type = acc_type;
	}
	int Get_Account_Num()
	{
		return this->Account_Number;
	}
	float Get_Balance()
	{
		return this->Balance;
	}
	int Get_Account_Type()
	{
		return this->Account_Type;
	}
	void Display()
	{
		cout << "Account Number :" << this->Account_Number << endl;
		cout << "Balance :" << this->Balance << endl;
		if (this->Account_Type == 1)
		{
			cout << "Account Type : Saving Account" << endl;
		}
		else
		{
			cout << "Account Type : Current Account" << endl;
		}
	}
	~Account()
	{

	}
};

class Current :public Account
{
private:
	int Panelty_Amount;
public:
	Current() :Account::Account()
	{

		this->Panelty_Amount = 20;

	}
	Current(int acc_n, float b, int acc_t, int p_a) :Account::Account(acc_n, b, acc_t)
	{

		this->Panelty_Amount = p_a;

	}
	void set_panelty(int p)
	{
		this->Panelty_Amount = p;
	}
	void Panelty()
	{
		if (Balance < 200 && Account_Type == 2)
		{
			this->Balance = Balance - Panelty_Amount;
		}
	}
};

class Saving : public Account
{
private:
	int No_of_Years;

public:
	Saving() :Account::Account()
	{
		this->No_of_Years = 0;
	}
	Saving(int acc_n, float b, int acc_t, int t) :Account::Account(acc_n, b, acc_t)
	{

		this->No_of_Years = t;

	}
	void set_years(int y)
	{
		this->No_of_Years = y;
	}
	void Interest()
	{
		this->Balance = Balance * (1 + 2 * this->No_of_Years);
	}
};

class Person
{
protected:
	char* First_Name;
	char* Last_Name;
	int Age;
	char* SSN;
	char* Phone_Number;
	char* Email;
public:
	Person()
	{
		this->First_Name = nullptr;
		this->Last_Name = nullptr;
		this->Age = 0;
		this->SSN = nullptr;
		this->Phone_Number = nullptr;
		this->Email = nullptr;
	}
	Person(char* f, char* l, int a, char* ssn, char* p, char* e)
	{
		strcopy(this->First_Name, f);
		strcopy(this->Last_Name, l);
		this->Age = a;
		strcopy(this->SSN, ssn);
		strcopy(this->Phone_Number, p);
		strcopy(this->Email, e);
	}
	///////////////////////////////////////Setters
	void set_fname(char* f)
	{
		strcopy(this->First_Name, f);
	}
	void set_lname(char* l)
	{
		strcopy(this->Last_Name, l);
	}
	void set_age(int a)
	{
		this->Age = a;
	}
	void set_ssn(char* s)
	{
		strcopy(this->SSN, s);
	}
	void set_phone(char* p)
	{
		strcopy(this->Phone_Number, p);
	}
	void set_email(char* e)
	{
		strcopy(this->Email, e);
	}
	////////////////////////////////////////////////////////////
	void strcopy(char*& des, char* src)
	{
		int len = 0;
		for (int i = 0; src[i] != '\0'; i++)
		{
			len++;
		}
		des = new char[len + 1];
		for (int i = 0; i < len + 1; i++)
		{
			des[i] = src[i];
		}
	}
	void Display()
	{
		cout << "First Name :" << this->First_Name << endl;
		cout << "Last Name :" << this->Last_Name << endl;
		cout << "Age :" << this->Age << endl;
		cout << "SSN :" << this->SSN << endl;
		cout << "Phone Number :" << this->Phone_Number << endl;
		cout << "Email :" << this->Email << endl;
	}




};

class Employee :public Person
{
private:
	int Employee_ID;
	float Salary;
public:
	Employee() :Person::Person()
	{
		this->Employee_ID = 0;
		this->Salary = 0.0;
	}
	Employee(char* f, char* l, int a, char* ssn, char* p, char* e, int e_id, float s) : Person::Person(f, l, a, ssn, p, e)
	{
		this->Employee_ID = e_id;
		this->Salary = s;

	}
	int get_employee_id()
	{
		return this->Employee_ID;
	}
	void set_emp_id(int i)
	{
		this->Employee_ID = i;
	}
	void set_salary(float s)
	{
		this->Salary = s;
	}

	void Display()
	{
		Person::Display();
		cout << "Employee Id :" << this->Employee_ID << endl;
		cout << "Salary :" << this->Salary << endl;
	}
};

class Customer :public Person
{
private:
	int Customer_ID;
	char* Card_Number;
	Account* My_Account;
	//ATM Machine;
public:
	Customer()
	{
		this->My_Account = new Account;
		this->Customer_ID = 0;
		this->Card_Number = 0;
	}
	Customer(char* f, char* l, int a, char* ssn, char* p, char* e, int c_id, char* c_no, Account acc, ATM mac) : Person::Person(f, l, a, ssn, p, e)
	{
		this->Customer_ID = c_id;
		strcopy(this->Card_Number, c_no);
		/*this->Machine.Set_Location(mac.Get_Location());
		this->Machine.Set_Managed(mac.Get_Managed());*/
		this->My_Account = new Account;
		this->My_Account->Set_Account_Num(acc.Get_Account_Num());
		this->My_Account->Set_Account_Type(acc.Get_Account_Type());
		this->My_Account->Set_Balance(acc.Get_Balance());
	}

	~Customer()
	{
		this->My_Account->~Account();
	}
	///////////////////////////////////////Setters
	/*void set_fname(char* f)
	{
		strcopy(this->First_Name, f);
	}
	void set_lname(char* l)
	{
		strcopy(this->First_Name, l);
	}
	void set_age(int a)
	{
		this->Age = a;
	}
	void set_ssn(double s)
	{
		this->SSN = s;
	}
	void set_phone(double p)
	{
		this->Phone_Number = p;
	}
	void set_email(char* e)
	{
		strcopy(this->Email, e);
	}*/
	void set_account(int n, float b, int t, int y_or_p)
	{
		if (t == 1)
		{
			Saving* obj = new Saving;
			obj->Set_Account_Num(n);
			obj->Set_Balance(b);
			obj->Set_Account_Type(t);
			obj->set_years(y_or_p);
			this->My_Account = obj;
		}
		else
		{
			Current* obj = new Current;
			obj->Set_Account_Num(n);
			obj->Set_Balance(b);
			obj->Set_Account_Type(t);
			obj->set_panelty(y_or_p);
			this->My_Account = obj;
		}

	}
	void set_acc_num(int n)
	{
		this->My_Account->Set_Account_Num(n);
	}
	void set_acc_balance(float b)
	{
		this->My_Account->Set_Balance(b);
	}
	void set_acc_type(int t)
	{
		this->My_Account->Set_Account_Type(t);
	}
	////////////////////////////////////////////////////////////
	void set_cutomerid(int id)
	{
		this->Customer_ID = id;
	}
	void set_card_num(char* num)
	{
		strcopy(this->Card_Number, num);
	}
	void strcopy(char*& des, char* src)
	{
		int len = 0;
		for (int i = 0; src[i] != '\0'; i++)
		{
			len++;
		}
		des = new char[len + 1];
		for (int i = 0; i < len + 1; i++)
		{
			des[i] = src[i];
		}
	}
	int get_customer_id()
	{
		return this->Customer_ID;
	}
	void Withdraw_Amount(float amount)
	{
		this->My_Account->Withdraw_Amount(amount);
	}
	void Deposit_Amount(float amount)
	{
		this->My_Account->Deposit_Amount(amount);
	}

	void Display()
	{
		Person::Display();
		cout << "Customer Id :" << this->Customer_ID << endl;
		cout << "Card Number :" << this->Card_Number << endl;
		this->My_Account->Display();
	}
};

class ATM
{
private:
	char* ATM_Location;
	char* Managed_By;
public:
	void Set_Location(char* atm_l)
	{
		strcopy(this->ATM_Location, atm_l);

	}
	void Set_Managed(char* atm_m)
	{
		strcopy(this->Managed_By, atm_m);

	}
	char* Get_Location()
	{
		return this->ATM_Location;
	}
	char* Get_Managed()
	{
		return this->Managed_By;
	}
	void strcopy(char*& des, char* src)
	{
		int len = 0;
		for (int i = 0; src[i] != '\0'; i++)
		{
			len++;
		}
		des = new char[len + 1];
		for (int i = 0; i < len + 1; i++)
		{
			des[i] = src[i];
		}
	}
};

int main()
{
	//Declairing an Instance of Bank
	Bank Meezan_Bank;
	//--------------------------------------------------
	//Input files for Reading Data
	char cutomer_details[] = "customer.txt";
	char employee_details[] = "employee.txt";
	//--------------------------------------------------
	//Initializing All Data Members of Bank
	int branch_code = 640;
	char address[] = "barket market, faisal town, lahore";
	char name[] = "Meezan Bank";
	Meezan_Bank.set_code(branch_code);
	Meezan_Bank.set_address(address);
	Meezan_Bank.set_name(name);
	Meezan_Bank.Populate_Customer(cutomer_details);
	Meezan_Bank.Populate_Employee(employee_details);
	//--------------------------------------------------

	Meezan_Bank.Display_Customers();

	Meezan_Bank.Display_Employees();

	//I also have make funtion (add_customer) which we can use to add customer and then 
	//that customer will gonna append at last index of List_of_Customers.
	//Same as above the funtionality have been implemented for Emplyee

	cout << "\n\n |----------------  Depositing Amount 1200 in Customer 702's Account  --------------------|" << endl;
	Meezan_Bank.Deposit_Amount(702, 1200);//adding balance in account of Customer 702
	cout << "\n\n |-----------------  Withdrawing Amount 15000 from the Account of Customer 703 ------------------|" << endl;
	Meezan_Bank.Withdraw_Amount(703, 15000);//withdrawing amount from account of Customer 703;

	//now checking again all the details of bothe customers

	cout << "\n|-----------------------  Printing Details of Customer 702  ---------------------------|" << endl;
	Meezan_Bank.Display_Customer_by_Id(702);
	cout << "\n|-----------------------  Printing Details of Customer 703  ---------------------------|" << endl;
	Meezan_Bank.Display_Customer_by_Id(703);
}
