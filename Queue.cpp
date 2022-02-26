#include <iostream>
using namespace std;
#include "Queue.h"

void Queue::init()
{
  count = 0;
}

void Queue::print()
{
  if (count <= 0)
  {
    cout << "Queue is empty" << endl;
    return;
  }

  for (size_t i = 0; i < count; i++)
    cout << queue[i].value << " ";
  cout << "\n";
}

void Queue::push(int el)
{
  Item *p;
  Item item;
  p = queue;
  item.value = el;
  item.prev = count ? &queue[count - 1] : nullptr;

  try
  {
    queue = new Item[count + 1];
    for (int i = 0; i < count; i++)
      queue[i] = p[i];

    queue[count] = item;
    count++;

    if (count > 1)
      delete[] p;
  }
  catch (bad_alloc e)
  {
    cout << e.what() << endl;
    queue = p;
  }
}

int Queue::pop()
{
  if (count <= 0)
  {
    cout << "Queue is empty" << endl;
    return -1;
  }

  try
  {
    Item *p;
    Item item;

    item = queue[0];
    p = new Item[count - 1];

    count--;

    for (int i = 0; i < count; i++)
      p[i] = queue[i + 1];

    if (count > 0)
      delete[] queue;

    queue = p;
    return item.value;
  }
  catch (bad_alloc e)
  {
    cout << e.what() << endl;
    return -1;
  }
}

Queue Queue::copy()
{
  Queue newQueue;
  newQueue.init();

  for (size_t i = 0; i < count; i++)
    newQueue.push(queue[i].value);
  return newQueue;
}

int Queue::length()
{
  return count;
}

Queue Queue::join(Queue q1, Queue q2)
{
  Queue q3 = q1.copy();
  Queue q2_copy = q2.copy();

  for (size_t i = 0; i < q2.length(); i++)
    q3.push(q2_copy.pop());
  return q3;
}