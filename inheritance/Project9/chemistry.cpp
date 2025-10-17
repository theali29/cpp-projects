#include "chemistry.h"
chemistry::chemistry()
{
	cmarks = 0;
}
chemistry::chemistry(int a)
{
	cmarks = a;
}
void chemistry::setcmarks(int a)
{
	cmarks = a;
}
int chemistry::getcmarks()
{
	return cmarks;
}
void chemistry::display()const
{
	cout << "Chemistry=" << cmarks << endl;
}
chemistry::~chemistry()
{
}