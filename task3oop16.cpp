#include <iostream> 
using namespace std;
template < class T >
bool isEqualTo(const T& a1, const T& a2)
{
    if (a1 == a2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
class Complex
{
private:
    int real;
    int imaginary;
    friend ostream& operator<<(ostream&, Complex&);
public:
    
    Complex(int realPart, int iPart)
    {
        real = realPart;
        imaginary = iPart;
    }
    bool operator==(const Complex& c) const
    {
        if ((real == c.real) && (imaginary == c.imaginary))
        {
            return real&&imaginary;
        }
    }
 
}; 


ostream& operator<<(ostream& out, Complex& obj)
{
    if (obj.imaginary > 0)
    {
        out << obj.real << " + " << obj.imaginary << "i";
    }
    else if (obj.imaginary == 0) 
    {
        out << obj.real;
    }
    else {
        out << obj.real << " - " << -obj.imaginary << "i";
    }
    return out;
} 

int main()
{
    int a; 
    int b; 

    cout << "Enter two integer values: "; 
    cin >> a >> b;
    cout << a << " and " << b << " are ";
        
    if (isEqualTo(a, b))
    {
        cout << "equal." << endl;
    } 
    else
    {
        cout << "not equal." << endl;
    }


    char c; 
    char d; 

  
    cout << "\nEnter two character values: "; cin >> c >> d;
    cout << c << " and " << d << " are "
        << (isEqualTo(c, d) ? "equal" : "not equal") << '\n';

    double e; 
    double f; 

    cout << "\nEnter two double values: "; cin >> e >> f;
    cout << e << " and " << f << " are "
        << (isEqualTo(e, f) ? "equal" : "not equal") << '\n';

    Complex g(10, 5); 
    Complex h(10, 5); 

    
    cout << "\nThe class objects " << g << " and " << h << " are "
        << (isEqualTo(g, h) ? "equal" : "not equal") << '\n';
} 