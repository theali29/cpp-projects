#include <iostream>
using namespace std;
class Vehicle {
protected:
	float price;
	float mileage;
	
public:
	Vehicle() 
	{
		price = 0.0;
		mileage = 0.0;
	}
	Vehicle(float mil, float pr)
	{
		mileage = mil;
		price = pr;
	}
	float getMileage() {
		return mileage;
	}
	float getPrice() {
		return price;
	}
	virtual void display()
	{
		
	}
};
class Car :public Vehicle {
protected:
	float ownershipCost;
	int warranty;
	int seatingCapacity;
char* fuelType;
public:
	int size = 0;
	Car() 
	{
		fuelType = new char[size];
		ownershipCost = 0.0;
		warranty = 0;
		seatingCapacity = 0;
	}
	Car(float mil, float pr, float oc, int w, int sc, const char*ft) :Vehicle(mil, pr) 
	{
		size = strlen(ft);
		fuelType = new char[size+1];
		for (int i = 0; i < size; i++)
		{
			fuelType[i] = ft[i];
		}
		fuelType[size] = '\0';

		ownershipCost = oc;
		warranty = w;
		seatingCapacity = sc;
	}
	char getFuelType()
	{
		return *fuelType;
	}
	float getownercost()
	{
		return ownershipCost;
	}
	int getWarranty() {
		return warranty;
	}
	int getSeatCapacity()
	{
		return seatingCapacity;
	}

	void display() {
		cout << "Car\n";
		cout << "Mileage: " << mileage << endl;
		cout << "Price: " << price << endl;
		cout << "Ownership Cost: " << ownershipCost << endl;
		cout << "Fuel type: " << fuelType << endl;
		cout << "Seating capacity: " << seatingCapacity << endl;
		cout << "Warranty: " << warranty << endl;
	

	}
};
class Bike :public Vehicle {
protected:
	char* coolingType;
	int numberCylinders;
	int numberGears;
	
public:
	int size=0;
	Bike() 
	{
		coolingType=new char[size];
		 numberCylinders=0;
		 numberGears=0;
	}
	Bike(float mil, float pr, int nc, int ng, const char* ct) :Vehicle(mil, pr)
	{
		size = strlen(ct);
		coolingType = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			coolingType[i] = ct[i];
		}
		coolingType[size] = '\0';
		numberCylinders = nc;
		numberGears = ng;
		
	}
	int getNumCylinders()
	{
		return numberCylinders;
	}
	int getNumGears() {
		return numberGears;
	}
	char getCoolType()
	{
		return *coolingType;
	}
	void display() {
		cout << "Bike\n";
		cout << "Mileage: " << mileage << endl;
		cout << "Price: " << price << endl;
		cout << "Number cylinders: " << numberCylinders << endl;
		cout << "Number gears: " << numberGears << endl;
		cout << "Cooling type: " << coolingType << endl;
	}
};
class audi :public Car
{
	char* modeltype;
public:

	audi(float mil, float pr, float oc, int w, int sc, const char* ft, const char* mt) :Car(mil, pr, oc, w, sc, ft)
	{
		size = strlen(mt);
		modeltype = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
	       modeltype[i] = mt[i];
		}
		modeltype[size] = '\0';

	}
	void display() {
		cout << "Audi "<<modeltype<<endl;
		cout << "Mileage: " << mileage << endl;
		cout << "Price: " << price << endl;
		cout << "Ownership Cost: " << ownershipCost << endl;
		cout << "Fuel type: " << fuelType << endl;
		cout << "Seating capacity: " << seatingCapacity << endl;
		cout << "Warranty: " << warranty << endl;


	}
};
class ford :public Car
{
	char* modeltype;
public:

	ford(float mil, float pr, float oc, int w, int sc, const char* ft, const char* mt) :Car(mil, pr, oc, w, sc, ft)
	{
		size = strlen(mt);
		modeltype = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			modeltype[i] = mt[i];
		}
		modeltype[size] = '\0';

	}
	void display() {
		cout << "Ford " << modeltype << endl;
		cout << "Mileage: " << mileage << endl;
		cout << "Price: " << price << endl;
		cout << "Ownership Cost: " << ownershipCost << endl;
		cout << "Fuel type: " << fuelType << endl;
		cout << "Seating capacity: " << seatingCapacity << endl;
		cout << "Warranty: " << warranty << endl;


	}
};
class Bajaj :public Bike
{
	char* maketype;
public:

	Bajaj(float mil, float pr, int nc, int ng, const char* ct, const char* mt) :Bike(mil, pr, nc, ng, ct)
	{
		size = strlen(mt);
		maketype = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			maketype[i] = mt[i];
		}
		maketype[size] = '\0';

	}
	void display() {
		cout << "Bajaj " << maketype << endl;;
		cout << "Mileage: " << mileage << endl;
		cout << "Price: " << price << endl;
		cout << "Number cylinders: " << numberCylinders <<endl;
		cout << "Number gears: " << numberGears << endl;
		cout << "Cooling type: " << coolingType << endl;
	}
};
class TVS :public Bike
{
	char* maketype;
public:

	TVS(float mil, float pr, int nc, int ng, const char* ct, const char* mt) :Bike(mil, pr, nc, ng, ct)
	{
		size = strlen(mt);
		maketype = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			maketype[i] = mt[i];
		}
		maketype[size] = '\0';

	}
	void display() {
		cout << "TVS " << maketype << endl;;
		cout << "Mileage: " << mileage << endl;
		cout << "Price: " << price << endl;
		cout << "Number cylinders: " << numberCylinders <<endl;
		cout << "Number gears: " << numberGears << endl;
		cout << "Cooling type: " << coolingType << endl;
	}
};
int main()
{
	Car car(134000, 320000, 29500, 3, 5, "Hybrid");
	Bike bike(56000, 52000, 3, 3, "liquid");
	car.display();
	cout << "---------------------------------" << endl;
	bike.display();
	audi au(12000, 200000, 220000, 2, 7, "electric", "Q-4 etron");
	au.display();
	cout << "******************************" << endl;
	ford fo(5000, 500000, 520000, 1, 4, "Gas", "Mustang Mach-E");
	fo.display();
	cout << "******************************" << endl;
	Bajaj ba( 39000, 134000, 1, 4, "Liquid", "Pulsar N200");
	ba.display();
	cout << "******************************" << endl;
	TVS ba1(12000, 240000, 1, 4, "Liquid", "Apache RTR 200 FI E100");
	ba1.display();
	cout << "********************************" << endl;
	system("pause");
	return 0;
}
