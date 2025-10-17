#include"RBT.h"
int main()
{
	RBT<int>R1;
	R1.root=R1.insert_node(R1.root, 67);
    R1.root = R1.insert_node(R1.root, 78); 
	R1.root = R1.insert_node(R1.root, 71);
    R1.root = R1.insert_node(R1.root, 54);
	R1.root = R1.insert_node(R1.root, 48);
    R1.root = R1.insert_node(R1.root, 44);
    R1.root = R1.insert_node(R1.root, 12);
    R1.root = R1.insert_node(R1.root, 90);
	R1.print_inorder(R1.root);
	cout << endl;
	R1.kthlargest(R1.root, 3);
	cout << endl;
	cout << "Mirror BST" << endl;
	R1.createmirror(R1.root);
	R1.print_inorder(R1.root);
	cout << endl;
	system("pause");
	return 0;
}