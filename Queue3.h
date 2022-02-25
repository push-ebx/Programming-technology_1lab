#pragma once
#include "Queue.h"

class Queue3 : private Queue
{
private:
  Queue queue;

public:
  int getEvenOfNumber();
  void push(int item);
  void init();
  int pop();
  void print();
  int length();
  Queue3 copy();
  Queue3 join(Queue3 q1, Queue3 q2);
};