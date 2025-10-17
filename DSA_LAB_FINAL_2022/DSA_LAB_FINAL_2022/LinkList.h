#pragma once
#include "Node.h"

template<class T>
class LinkList
{
public:
	Node<T>* head;
	LinkList()
	{
		head = NULL;
	}

    void show_2d_list(Node<T>* head) {
        Node<T>* right_ptr, * down_ptr = head;
        while (down_ptr) {
            right_ptr = down_ptr;
            while (right_ptr) {
                cout << right_ptr->data << "-----> ";
                right_ptr = right_ptr->right;
              
            }
            cout << "nullptr";
            cout << endl;
            cout <<"|\t|\t|" << endl;
            cout <<"v\tv\tv" << endl;
                
            down_ptr = down_ptr->down;
            
        }
    }
   
    
};

