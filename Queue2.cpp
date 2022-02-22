#include "Queue2.h"
#include <iostream>

int Queue2::getEvenOfNumber()
{
  Queue queue_copy = queue.copy();

  int c = 0;
  for (int i = 0; i < queue.length(); i++)
    c += queue_copy.pop() % 2 == 0 ? 1 : 0;
  return c;
}

void Queue2::push(int item)
{
  queue.push(item);
}

void Queue2::init()
{
  queue.init();
}

int Queue2::pop()
{
  return queue.pop();
}

void Queue2::print()
{
  queue.print();
}

int Queue2::length()
{
  return queue.length();
}

Queue2 Queue2::copy()
{
  Queue2 newQueue;
  newQueue.init();

  Queue queue_copy = queue.copy();

  for (size_t i = 0; i < queue.length(); i++)
    newQueue.push(queue_copy.pop());
  return newQueue;
}

Queue2 Queue2::join(Queue2 q1, Queue2 q2)
{
  Queue2 q3 = q1.copy();
  Queue2 q2_copy = q2.copy();
  int len = q2.length();
  
  for (size_t i = 0; i < len; i++)
    q3.push(q2.pop());
  return q3;
}