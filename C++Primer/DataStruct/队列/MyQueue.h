
#ifndef LOOP_QUEUE_H
#define LOOP_QUEUE_H
/**
环形队列的C++实现
C++的类名并不比与类名相同
**/
class LoopQueue
{
public:
  LoopQueue(int queueCapacity); //initQueue(&Q)创建队列
  virtual ~LoopQueue();         //destoryQueue(&Q)销毁队列
  void clearQueue();            //clearQueue(&Q)清空队列
  bool queueEmpty() const;      //queueEmpty(&Q)判空队列
  bool queueFull() const;       //queueFull(&Q)判满队列
  int queueLength() const;      //queueLength(&Q)判断队列的长度
  bool enQueue(int element);    //enQueue(&Q element)进入队列
  bool deQueue(int &element);   //deQueue(&Q element)首元素出队
  void queueTraverse();         //queueTraverse(&Q,visit())遍历队列
private:
  int *m_lqueue;        //队列数组首指针
  int m_lqueueLen;      //队列长度
  int m_lqueueCapacity; //队列容量
  int m_lqueueHead;
  int m_lqueueTail;
};
#endif // LOOP_QUEUE