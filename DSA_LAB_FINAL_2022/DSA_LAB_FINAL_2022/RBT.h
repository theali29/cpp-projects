#pragma once
#include"Node2.h"
template<class T>
class RBT
{
public:
	Node2<T>* root;
	RBT()
	{
		root = NULL;
	}
	Node2<T>* insert_node(Node2<T>* root, int key)
	{
		Node2<T>* newnode = new Node2<T>(key);
		Node2<T>* temp = root;
		if (root == NULL)
		{
			root = newnode;
			
	    }
		else if (temp->key < newnode->key)
		{
			root->right=insert_node(temp->right, newnode->key);
			
		}
		else
		{
			root->left=insert_node(temp->left, newnode->key);
		
		}
		return root;
	}
	void print_inorder(Node2<T>* root)
	{
		if(root==NULL)
		{
			return;
		}
		print_inorder(root->left);
		cout << root->key << " ";
		print_inorder(root->right);
	

	}
	void PrintKthlargestelement(Node2<T>* root, int k,int &count)
	{
		if (root == nullptr||count>=k)
		{
			return;
		}
		PrintKthlargestelement(root->right, k, count);
		count++;
		if (count == k)
		{
			cout << "Kth largest element " << root->key << endl;
		}
		PrintKthlargestelement(root->left, k, count);

	}
	void createmirror(Node2<T>* root)
	{
		if (root == NULL)
		{
			return;
		}
		else
		{
			Node2<T>* temp;

			createmirror(root->left);
			createmirror(root->right);
			temp = root->left;
			root->left = root->right;
			root->right = temp;

		}

	}

	void kthlargest(Node2<T>* root, int k)
	{
		int c = 0;
		PrintKthlargestelement(root, k, c);
	}
};

