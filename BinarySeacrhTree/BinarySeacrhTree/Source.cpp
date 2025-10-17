#include"BST.h"
template<class Type>
Type Count_and_Print_greater_Values(Node<Type>* root, Type key)
{
	int static count = 0;
	if (root == NULL)
	{
		return NULL;
	}
	else
	{
		if (root->key >= key)
		{
			cout << root->key << " ";
			count++;
		}
	}
	Count_and_Print_greater_Values(root->left, key);
    Count_and_Print_greater_Values(root->left, key);
	return count;
}


int main()
{
	BST<int>B1;
	BST<int>B2;
	int count = 0;
	/*Node<int>* a;*/
	int k = 0;
	
	B1.insert_node(5);
	B1.insert_node(3);

	B1.insert_node(6);
	B1.insert_node(2);

	
	B1.insert_node(4);

	B1.insert_node(1);
	B1.delete_node(B1.root,5);
	B1.Print_PreOrder(B1.root);	
	
	cout << endl;
	count=Count_and_Print_greater_Values(B1.root, 3);
	cout << endl;
	cout << count;

	B2.Print_PreOrder(B2.root);
	
}