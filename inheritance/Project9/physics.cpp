#include "physics.h"

physics::physics()
{
	bmarks = 0;
}
physics::physics(int b)
{
	bmarks = b;
}
void physics::setbmarks(int a)
{
	bmarks = a;
}
int physics::getbmarks()
{
	return bmarks;
}
void physics::display()const
{
	cout << "physics=" << bmarks << endl;
}
physics::~physics()
{
}