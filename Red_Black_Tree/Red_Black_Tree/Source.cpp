#include"RBT.h"
int main()
{

	int option;
	RBT<int> R1;
	Node<int>* R2;

	cout << "\n\n\n";
	cout << "\t\t\t\t MAIN MENU\n";
	cout << "\t\t\t--------------------------------------------------------------------\n";
	cout << "\t\t\t\tPress 1 to insert values in the tree(one by one)\n";
	cout << "\t\t\t\tPress 2 for searching a value from the tree\n";
	cout << "\t\t\t\tPress 3 for pre - order traversal NLR\n";
	cout << "\t\t\t\tPress 4 for in - order traversal LNR\n";
	cout << "\t\t\t\tPress 5 for post - order traversal LRN\n";
	cout << "\t\t\t\tPress 6 for pre - order traversal 2 NRL\n";
	cout << "\t\t\t\tPress 7 for in - order traversal 2 RNL\n";
	cout << "\t\t\t\tPress 8 for post - order traversal 2 RLN\n";
	cout << "\t\t\t\tPress 9 for displaying parent of a node present in Tree\n";
	cout << "\t\t\t\tPress 10 to read integer values from the file input.txt	to create a red - black tree\n";
	cout << "\t\t\t\tPress 11 to delete all duplicate values from the tree\n";
	cout << "\t\t\t\tPress 12 to destroy the complete tree\n";
	cout << "\t\t\t\ttPress 13 to EXIT\n";

	cout << "\t\t\t--------------------------------------------------------------------\n";
	int value;
	int num = 0;
	do
	{

		cout << "\n\t\t\t\tEnter an Option: ";
		cin >> option;
		switch (option)
		{
		case 1:



			cout << "\n\n\n\t\t\t\tEnter how many values you want to insert:";

			cin >> num;
			for (int i = 0; i < num; i++)
			{
				cout << "\n\t\t\t\tEnter value " << (i + 1) << ": ";
				cin >> value;
				R1.insert(value);
			}

			continue;;
		case 2:




			cout << "\n\n\n\t\t\t\tEnter a value you want to search from tree: ";
			/*cout << "\t\t\t\t";*/

			cin >> value;
			R2 = R1.search(R1.root, value);
			if (R2 == NULL)
			{
				cout << "\n\t\t\t\tThis node's value does not exit in Tree";
			}
			else
			{
				cout << "\n\t\t\t\tSearched value is " << endl;
				cout << R2->data << endl;
			}

			continue;
		case 3:

			cout << "\nFor Pre-Order Traversal NLR ";
			R1.preorder(R1.root);
			continue;;
		case 4:
			cout << "\nFor InOrder Traversal LNR ";
			R1.inorder(R1.root);
			continue;;
		case 5:


			cout << "\nFor PostOrder Traversal LRN ";
			R1.postorder(R1.root);
			continue;;

		case 6:



			cout << "\nFor PreOrder Traversal 2 NRL ";
			R1.preorder2(R1.root);
			continue;;
		case 7:

			cout << "\nFor InOrder Traversal 2 RNL ";
			R1.inorder2(R1.root);
			continue;;
		case 8:


			cout << "\nFor PostOrder Traversal 2 RLN ";
			R1.postorder2(R1.root);
			continue;;
		case 9:
			cout << "\nEnter Node value to display a parent ";
			cin >> value;
			cout << "\nDisplaying parent of node in the tree";
			R1.display_parent(value);
			continue;;
		case 10:

			cout << "\nReading integer values from input.txt file" << endl;
			R1.readFile();
			continue;;
		case 11:


			cout << "\t\t\t\tDuplicate values does not exist in BST" << endl;
			system("pause");
		case 12:
			cout << "\t\t\t\tTree is destroyed " << endl;
			R1.root = R1.destroy(R1.root);

		}
		cout << "\n";
	} while (option != 13);

}
   
	
	
