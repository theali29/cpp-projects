#include"DDL.h"
int main()
{
	DDL<int>D1;
	D1.insert(1);
	D1.insert(2);
	D1.insert(67);
	D1.insert(21);
	D1.insert(56);
	D1.insert(89);
	D1.insert(11);
	D1.insert(29);
	D1.insert(78);
	D1.print();

    int max=D1.maximumvalue(D1.head,0);
	cout << "Maximum Value " <<max<< endl;
	int min = D1.minimumvalue(D1.head, 1);
	cout << "Minimum Value " << min << endl;
	D1.printinrange(D1.head,1,10);
	
	system("pause");
	return 0;
}