#pragma once
#include "Queue.h"

class Queue1 : public Queue
{
private:

public:
  int getEvenOfNumber();
  Queue1 copy();
  Queue1 join(Queue1 q1, Queue1 q2);
};