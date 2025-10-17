#include <iostream>
using namespace std;
class LocalPhone
{
private:
    char*phonenumber=new char[100];


public:
    void input()
    {
        cout << "Enter Phone number " << endl;
        cin.getline(phonenumber,100);
    }
    void display()
    {
        cout << "Local Phone:"  ;
        cout << phonenumber;
        cout << endl;
    }
};


class NatPhone : public LocalPhone
{
private:
    char* cityCode= new char[100];


public:
    void input()
    {
        cout << "Enter city code " << endl;
        cin.getline(cityCode,100);
    }
    void display()
    {
        cout << "City Code " << endl;
        cout << cityCode << endl;;
    }
};


class IntPhone : public NatPhone
{
private:
    char* countryCode=new char[100];


public:
    void input()
    {
        cout << "Enter country code " << endl;
        cin.getline(countryCode,100);
    }
    void display()
    {
        cout << "Country Code " << endl;
        cout << countryCode << endl;
    }
};




int main()
{
    LocalPhone p;
    p.input();
    p.display();
    NatPhone n;
    n.input();
    n.display();
    IntPhone i;
    i.input();
    i.display();

    return 0;
}
