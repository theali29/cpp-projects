#include "List.h"
#include<iostream>
using namespace std;

template<class type>
List<type>::List()
{

}
template<class type>
List<type>::List(type* arr, int ms, int cs)
{

	this->maxSize = ms;


}
template<class type>
List<type>::List(List& l1)
{

}
template<class type>
List<type>::~List()
{

}
