#pragma once
#include"Queue.h"
#include<iostream>
using namespace std;
template<class type>
class MyStack 
{
    Queue<int> q1, q2;
    int count = 0;

public:
    type y;
    void push(type x)
    {
        q2.push(x);
        count++;
        while (!q1.isempty())
        {
             y = q1.Front();
            q2.push(y);
            q1.pop();
        }
        Queue<int>temp = q1;
        q1 = q2;
        q2 = temp;

    }

    void pop()
    {
        q1.pop();
         count--;
    }
   

    type top()
    {
        return q1.Front();
    }

    int size()
    {
        return count;
    }
};

