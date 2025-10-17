#include"Queue.h"
template<class T>			
MyQueue<T>reverseQueue(MyQueue <T> obj)
{
    int s = obj.size();
    MyQueue<char> ans;
    for (int i = 0; i < s; i++) 
    {
        for (int j = 0; j < s-i-1; j++)
        {
            char x = obj.tfront();
            obj.dequeue();
            obj.enqueue(x);
        }
        ans.enqueue(obj.tfront());
        obj.dequeue();
    }
    return ans;
}
	

int main()
{
	MyQueue<char>q1;
	q1.enqueue('D');
	q1.enqueue('S');
	q1.enqueue('A');
	q1.enqueue('L');
	q1.enqueue('A');
	q1.enqueue('B');
	q1.display();
	
	cout << "-----------------"<<endl;
	q1=reverseQueue(q1);
    q1.display();
}