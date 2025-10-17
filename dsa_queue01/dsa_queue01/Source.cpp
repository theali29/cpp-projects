#include"Queue.h"

int main()
{
	Queue<int>obj(6);
	obj.deque();      //deQueue 

    cout << "Queue created:" << endl;
    obj.enque(10);
    obj.enque(30);
    obj.enque(40);
    obj.enque(35);
    obj.enque(20);
    obj.enque(15);
    obj.enque(5);
    int p = 0;
    obj.printqueue();
    
    p=obj.tfront();
    cout << p << endl;
    //deQueue =>removes 10
  
    //queue after dequeue
}
