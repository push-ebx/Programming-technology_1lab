#include <iostream>
#include "Queue1.h"
#include "Queue2.h"
#include "Queue3.h"

using namespace std;

void show_menu();
int *array_input(int count);
template <typename T>
void fill_queue(T *queue);

enum commands { PUSH = 1, POP, PRINT, EVEN, COPY, JOIN, EXIT };

int main()
{
  bool is_exit = false;
  int act, mod, item;
  cout << "Select the queue with the desired modifier\n\t1 - public\n\t2 - protected\n\t3 - private\n>> ";
  cin >> mod;

  Queue1 queue1;
  queue1.init();
  Queue2 queue2;
  queue2.init();
  Queue3 queue3;
  queue3.init();

  Queue1 queue1_2;
  queue1_2.init();
  Queue2 queue2_2;
  queue2_2.init();
  Queue3 queue3_2;
  queue3_2.init();

  system("cls");
  show_menu();

  while (!is_exit)
  {
    cout << "\nEnter action: ";
    cin >> act;
    system("cls");
    show_menu();

    switch (act)
    {
    case PUSH:
      cout << "Enter element: ";
      cin >> item;
      if (mod == 1) queue1.push(item);
      else if (mod == 2) queue2.push(item);
      else if (mod == 3) queue3.push(item);
      break;
    case POP:
      if (mod == 1) queue1.pop();
      else if (mod == 2) queue2.pop();
      else if (mod == 3) queue3.pop();
      break;
    case PRINT:
      if (mod == 1) queue1.print();
      else if (mod == 2) queue2.print();
      else if (mod == 3) queue3.print();
      break;
    case EVEN:
      int ans;
      if (mod == 1) ans = queue1.getEvenOfNumber();
      else if (mod == 2) ans = queue2.getEvenOfNumber();
      else if (mod == 3) ans = queue3.getEvenOfNumber();
      cout << ans << endl;
      break;
    case COPY:
      if (mod == 1) queue1_2 = queue1.copy();
      else if (mod == 2) queue2_2 = queue2.copy();
      else if (mod == 3) queue2_2 = queue2.copy();

      cout << "Queue copied" << endl;
      break;
    case JOIN:
    {
      if (mod == 1)
      {
        fill_queue(&queue1_2);
        queue1 = queue1.join(queue1, queue1_2);
      }
      else if (mod==2)
      {
        fill_queue(&queue2_2);
        queue2 = queue2.join(queue2, queue2_2);
      }
      else if (mod==3)
      {
        fill_queue(&queue3_2);
        queue3 = queue3.join(queue3, queue3_2);
      }
      break;
    }
    case EXIT:
      is_exit = true;
      break;
    }
  }
  return 0;
}

void show_menu()
{
  cout << "1 - Add queue item" << endl;
  cout << "2 - Pop an element from the queue" << endl;
  cout << "3 - Display queue on screen" << endl;
  cout << "4 - Get even of number" << endl;
  cout << "5 - Creating a copy of the queue" << endl;
  cout << "6 - Merging two queues" << endl;
  cout << "7 - Exit from the program\n" << endl;
}

int *array_input(int count)
{
  int el;
  int *array;
  array = new int[count];

  for (size_t i = 0; i < count; i++)
  {
    cout << i + 1 << " element: ";
    cin >> el;
    array[i] = el;
  }
  return array;
}

template <typename T>
void fill_queue(T *queue)
{
  int count, el;
  cout << "Enter count elemts in queue: ";
  cin >> count;
  int *array = array_input(count);
  queue->init();

  for (size_t i = 0; i < count; i++)
    queue->push(array[i]);
}