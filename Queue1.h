#pragma once
#include "Queue.h"

class Queue1 : public Queue
{
private:
  Queue queue;

public:
  int getEvenOfNumber();
  Queue1 copy();
  Queue1 join(Queue1 q1, Queue1 q2);
  void push(int item);
  void init();
  int pop();
  void print();
  int length();
};