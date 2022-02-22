#include <iostream>
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

int Queue3::getEvenOfNumber()
{
  Queue queue_copy = queue.copy();

  int c = 0;
  for (int i = 0; i < queue.length(); i++)
    c += queue_copy.pop() % 2 == 0 ? 1 : 0;
  return c;
}

void Queue3::push(int item)
{
  queue.push(item);
}

void Queue3::init()
{
  queue.init();
}

int Queue3::pop()
{
  return queue.pop();
}

void Queue3::print()
{
  queue.print();
}

int Queue3::length()
{
  return queue.length();
}

Queue3 Queue3::copy()
{
  Queue3 newQueue;
  newQueue.init();

  Queue queue_copy = queue.copy();

  for (size_t i = 0; i < queue.length(); i++)
    newQueue.push(queue_copy.pop());
  return newQueue;
}

Queue3 Queue3::join(Queue3 q1, Queue3 q2)
{
  Queue3 q3 = q1.copy();
  Queue3 q2_copy = q2.copy();
  int len = q2.length();
  
  for (size_t i = 0; i < len; i++)
    q3.push(q2.pop());
  return q3;
}