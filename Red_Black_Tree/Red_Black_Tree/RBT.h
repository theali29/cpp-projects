#pragma once
#include"Node.h"
#include <fstream>
template<class T>
//DSA Lab Project
// Red Black Tree
//Rules to insert in RBT
//1.If tree is empty create newnode as root node
//with color black.
//2.If tree is not empty create newnode as leaf node
// with color red.
//3.If parent of newnode is black then exit
//4.If parent of newnode is Red then check 
//color of parent's sibling of newnode
//(a) If color is black or null then do suitable rotation 
//and recolor
//(b) If color is red then recolor and also check if parent's
// parent of newnode is not root node then recolor it and recheck 
//and recolor
//root=Black
//no two adjacent root nodes
//count no of black nodes in each path
class RBT
{
public:
	Node<T>* root;
	RBT()
	{
      root = NULL;
	}
	void insert(const T&data);
	Node<T> *search(Node<T>*root,T data);
	void inorder(Node<T>* root);
	void inorder2(Node<T>* root);
	void postorder(Node<T>* root);
	void postorder2(Node<T>* root);
	void preorder(Node<T>* root);
	void preorder2(Node<T>* root);
	void readFile();
    Node<T>* destroy(Node<T>* root);
	void delete_duplicate(Node<T>* root);
	void display_parent(T data);
};

template<class T>
Node<T>* BSTInsert(Node<T>* root, Node<T>* pt)
{
    /* If the tree is empty, return a new node */
    if (root == NULL)
    { 
        pt->color = 0;  //0 is black
        return pt;
    }
    /* Otherwise, recur down the tree */
    if (pt->data < root->data)
    {
        root->left = BSTInsert(root->left, pt);
        pt->color = 1; //1 is red
        root->left->parent = root;
    }
    else if (pt->data > root->data)
    {
        root->right = BSTInsert(root->right, pt);
        pt->color = 1;
        root->right->parent = root;
    }

   
    return root;
}
template<class T>
void rotateLeft(Node<T>*& root, Node<T>*& pt)
{
    Node<T>* pt_right = pt->right;
    pt->right = pt_right->left;
    if (pt->right != NULL)
       pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_right;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;

    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}
template<class T>
void rotateRight(Node<T>*& root, Node<T>*& pt)
{
    Node<T>* pt_left = pt->left;

    pt->left = pt_left->right;

    if (pt->left != NULL)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_left;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;

    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}
template<class T>
void checkingviolation(Node<T>*& root, Node<T>*& pt)
{
    Node<T>* parent_pt = NULL;
    Node<T>* grand_parent_pt = NULL;
    //1 is red
    //no two adjacent red nodes
    while ((pt != root) && (pt->color == 1) &&(pt->parent->color == 1))
    {

        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        /*  Case : A
            
            Parent of pt is left child

            of Grand-parent of pt */
        if (parent_pt == grand_parent_pt->left)
        {
            //uncle is parent's sibling
            Node<T>* uncle = grand_parent_pt->right;

            /* Case : 1
               The uncle of pt is also red
               Only Recoloring required */
            if (uncle != NULL && uncle->color ==
                1)
            {
                grand_parent_pt->color = 1;
                parent_pt->color = 0;
                uncle->color = 0;
                pt = grand_parent_pt;
            }

            else
            {
                /* Case : 2
                   pt is right child of its parent
                   Left-rotation required */
                if (pt == parent_pt->right)
                {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* Case : 3
                   pt is left child of its parent
                   Right-rotation required */
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color,
                    grand_parent_pt->color);
                pt = parent_pt;
            }
        }

        /* Case : B
           Parent of pt is right child
           of Grand-parent of pt */
        else
        {
            Node<T>* uncle = grand_parent_pt->left;

            /*  Case : 1
                The uncle of pt is also red
                Only Recoloring required */
            if ((uncle != NULL) && (uncle->color ==
                1))
            {
                grand_parent_pt->color = 1;
                parent_pt->color = 0;
                uncle->color = 0;
                pt = grand_parent_pt;
            }
            else
            {
                /* Case : 2
                   pt is left child of its parent
                   Right-rotation required */
                if (pt == parent_pt->left)
                {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /*Case : 3
                   pt is right child of its parent
                   Left-rotation required */
                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color,
                    grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }

    root->color = 0;
}
template<class T>
void RBT<T>:: display_parent(T data)
{
    Node<T>* node =  search(root, data);
    
    if (node == NULL)
    {
        cout << "No such node exists " << endl;
    }
    else if (node->parent == NULL)
    {
        cout << "\nParent Node doesnt exit " << endl;
        return;
    }

    cout <<"\n"<<node->parent->data << "(" << node->parent->color << ")" << endl;
}
template<class T>
void RBT<T>::insert(const T& data)
{
    Node<T>* newnode = new Node<T>;
    newnode->data = data;
    newnode->right = NULL;
    newnode->left = NULL;
    // Do a normal BST insert
    root = BSTInsert(root, newnode);

    // fix Red Black Tree violations
    checkingviolation(root, newnode);
}
template<class T>
void RBT<T>:: readFile()
{
    ifstream fin;
    fin.open("input.txt");
    T value;
    while (!fin.eof())
    {
        fin >> value;
        insert(value);
    }

}
template<class T>
Node<T>* RBT<T>::search(Node<T>*root,T data)
{
    Node<T>* node = root;
    if (node == NULL)
        return NULL;
    if (node!=NULL&&node->data == data)
    {
        return node;
    }
    if (node->data > data)
    {
       return node->left = search(node->left, data);

    }
    return node->right = search(node->right, data);
     
    
}
template<class T>
void RBT<T>::inorder(Node<T>* root)
{
    //LNR
    Node<T>* newnode = root;
    if (newnode == NULL)
        return;
    inorder(newnode->left);
    cout << newnode->data<< "(" << newnode->color << ")" << " ";
    inorder(newnode->right);
}
template<class T>
void RBT<T>::inorder2(Node<T>* root)
{
    //RNL

    Node<T>* newnode = root;
    if (newnode == NULL)
        return;
    inorder2(newnode->right);
    cout << newnode->data<< "(" << newnode->color << ")" << " ";
    inorder2(newnode->left);
    
}
template<class T>
void RBT<T>::preorder(Node<T>* root)
{
    //NLR
    Node<T>* newnode = root;
    if (newnode == NULL)
        return;
    cout << newnode->data<<"(" << newnode->color << ")" << " ";
    preorder(newnode->left);
    preorder(newnode->right);
}
template<class T>
void RBT<T>::preorder2(Node<T>* root)
{
    //NRL
    Node<T>* newnode = root;
    if (newnode == NULL)
        return;
    cout << newnode->data<<"(" << newnode->color << ")" << " ";
    preorder2(newnode->right);
    preorder2(newnode->left);
 
}
template<class T>
void RBT<T>::postorder(Node<T>* root)
{
    //LRN
    Node<T>* newnode = root;
    if (newnode == NULL)
        return;
    postorder(newnode->left);
    cout << newnode->data << "(" << newnode->color << ")"<< " ";
    postorder(newnode->right);
}
template<class T>
void RBT<T>::postorder2(Node<T>* root)
{
    //RLN
    Node<T>* newnode = root;
    if (newnode == NULL)
        return;
    cout << newnode->data<<"("<<newnode->color<<")" << " ";
    postorder2(newnode->right);
    postorder2(newnode->left);

}
template<class T>
Node<T>* RBT<T>::destroy(Node<T>*root)
{

    if (root == NULL)
    {
        return NULL;
    }
    root->left = destroy(root->left);
    root->right = destroy(root->right);
    delete root;
}