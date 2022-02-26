#include "Queue1.h"
#include <iostream>

int Queue1::getEvenOfNumber()
{
  Queue queue_copy = queue.copy();

  int c = 0;
  for (int i = 0; i < queue.length(); i++)
    c += queue_copy.pop() % 2 == 0 ? 1 : 0;
  return c;
}

Queue1 Queue1::copy()
{
  Queue1 newQueue;
  newQueue.init();

  Queue queue_copy = queue.copy();

  for (size_t i = 0; i < queue.length(); i++)
    newQueue.push(queue_copy.pop());
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

void Queue1::push(int item)
{
  queue.push(item);
}

void Queue1::init()
{
  queue.init();
}

int Queue1::pop()
{
  return queue.pop();
}

void Queue1::print()
{
  queue.print();
}

int Queue1::length()
{
  return queue.length();
}