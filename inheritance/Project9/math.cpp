#include "math.h"

math::math()
{
	amarks = 0;
}
math::math(int a)
{
	amarks = a;
}
void math::setamarks(int a)
{
	amarks = a;
}
int math::getamarks()
{
	return amarks;
}
void  math::display()const
{
	cout << " math=" << amarks << endl;
}
math::~math()
{
}
