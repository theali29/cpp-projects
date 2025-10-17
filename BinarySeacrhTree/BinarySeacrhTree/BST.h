#pragma once
#include"Tree.h"
#include<iostream>
using namespace std;
template<class Type>
class BST :public Tree<Type>
{
public:
	Node<Type>* root;
	BST()
	{
		root = NULL;
	}
	BST(const BST& bst)
	{
		root = bst.root;
	}
	void insert_node(Type value)
	{
		Node<Type>* newnode = new Node<Type>;
		newnode->key = value;
		
		Node<Type>* temp = root;
		
		while (1)
		{
			if (root == NULL)
			{
				root = newnode;
				temp = root;
				break;
			}
		
			else if (temp->key > newnode->key)
			{
				
				if (temp->left == NULL)
				{
					temp->left = newnode;
					break;
				}
				temp = temp->left;
			}
			else
			{
				
				if (temp->right == NULL)
				{
					temp->right = newnode;
					break;
				}
				temp = temp->right;
			}
		}
	}
	void Print_inOrder(Node<Type>*node)
	{
		if (node == NULL)
		{
			return;
		}
		Print_inOrder(node->left);

		cout << node->key<< " ";

		Print_inOrder(node->right);
	}
	void Print_PostOrder(Node<Type>* node)
	{
		if (node == NULL)
		{
			return ;
		}
		Print_PostOrder(node->left);
		Print_PostOrder(node->right);

		cout << node->key << " ";


		
	}
	void Print_PreOrder(Node<Type>* node)
	{
		if (node == NULL)
		{
			return ;
		}
		cout << node->key << " ";
		Print_PreOrder(node->left);
		Print_PreOrder(node->right);

		
	}
	bool is_empty()
	{
		return root == NULL;
	}
	Node<Type>* delete_node(Node<Type>*root,Type value)
	{
		if (root == NULL)
			return NULL;
		//for leafnode
		Node<Type>* current = root;
		Node<Type>* parent = root;
		Node<Type>* G_parent = root;
		while (current != NULL)
		{
			if (current->key == value)
				break;
			G_parent = parent;
			parent = current;
			if (current->key < value)
			{
				current = current->right;
			}
			else
			{
				current = current->left;
			}
			
		}
		if (current != NULL)
		{
			//for leaf node
			if (current->left == NULL && current->right == NULL)
			{
				if (parent->left->key == value)
				{
					parent->left = NULL;
				}
				else
				{
					parent->right = NULL;

				}
				
			}
			else if (current->left == NULL && current->right != NULL)
			{
				if (parent->left == current)
				{
					parent->left = current->right;
				}
				else
				{
					parent->right = current->right;
				}
				
			}
			else if (current->left != NULL && current->right == NULL)
			{
				if (parent->right == current)
				{
					parent->right = current->left;
				}
				else
				{
					parent->left = current->left;
				}
			}
			
			else
            {
				Node<Type>* p = NULL;
				Node<Type>* temp = current->right;
				while (temp->left != NULL)
				{
					p = temp;
					temp = temp->left;
				}
				if (p!= NULL)
				{
					p->left = temp->right;
				}
				else
				{
					current->right = temp->right;
				}
				current->key = temp->key;
				temp = NULL;
			} 
		}
		return current;
	}
	Node<Type>* minValueNode(Node<Type>* root)
	{
		Node<Type>* current = root;
		while (current&&current->left != NULL)
		{
			current = current->left;
		}
		return current;
	}

	~BST()
	{

	}

};

