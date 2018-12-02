
#include <iostream>
#include "MyQueue.h"
using namespace std;

int main()
{
    LoopQueue *p = new LoopQueue(4);
    p->enQueue(1);
    p->enQueue(2);
    p->enQueue(3);
    p->enQueue(4);
    p->enQueue(5);
    p->queueTraverse();
    int e = 0;
    p->deQueue(e);
    cout << "e=" << e << endl;
    p->deQueue(e);
    cout << "e=" << e << endl;
    p->queueTraverse();
    p->clearQueue();
    p->queueTraverse();
    p->enQueue(6);
    p->enQueue(7);
    p->queueTraverse();
    delete p;
    p = NULL;
    return 0;
}
