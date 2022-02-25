#pragma once
#include "Queue.h"

class Queue2 : protected Queue
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
  Queue2 copy();
  Queue2 join(Queue2 q1, Queue2 q2);
};