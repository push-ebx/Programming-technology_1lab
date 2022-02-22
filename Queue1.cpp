#include "Queue1.h"
#include <iostream>

int Queue1::getEvenOfNumber()
{
  int *array = getArray();
  int c = 0;
  for (int i = 0; i < count; i++)
    c += array[i] % 2 == 0 ? 1 : 0;
  return c;
}

Queue1 Queue1::copy()
{
  Queue1 newQueue;
  newQueue.init();

  int *array = getArray();
  for (size_t i = 0; i < count; i++)
    newQueue.push(array[i]);
    
  return newQueue;
}

Queue1 Queue1::join(Queue1 q1, Queue1 q2)
{
  Queue1 q3 = q1.copy();
  Queue1 q2_copy = q2.copy();

  for (size_t i = 0; i < q2.length(); i++)
    q3.push(q2_copy.pop());
  return q3;
}