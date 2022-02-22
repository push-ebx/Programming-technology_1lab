#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
  struct Item
  {
    int value;
    Item *prev;
  };

private:
  Item *queue;

protected:
  int count;
  int* getArray();

public:
  void init();
  int pop();
  void push(int item);
  void print();
  int length();
  Queue copy();
  Queue join(Queue q1, Queue q2);
};
#endif