
#include"List.h"
#include <iostream>
using namespace std;
template<class T>
int main()
{

	List<int>* obj[2];
	MyList<int> L1;
	L1.addElementAtFirstIndex(21)
	L1.addElementAtLastIndex(25);
	obj[1]=&L1;
	MyList<int> L2;
	L2.addElementAtFirstIndex(22)
		L2.addElementAtLastIndex(24);
	obj[2] = &L2;
	
obj[1].display();
obj[2].display();
cout << endl;
	obj.removeElementFromEnd();
	obj.display();

	cout << "Size: " << endl;
	cout << obj.Size() << endl;
	cout << "Last Element :" << endl;
	cout << obj.Last() << endl;



	return 0;
}