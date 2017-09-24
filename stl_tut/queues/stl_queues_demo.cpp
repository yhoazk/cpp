#include <iostream>
#include <queue>

using namespace std;

/*
Methods:
  - empty: boolean returns true if the queue is empty
  - size: size_t - returns the # of elements cointained in the queue
  - front
  - back
  - push
  - emplace
  - pop: void : removes the next element
  - swap: my_q.swap(other_queue)
*/


int main(int argc, char const *argv[]) {
  /*Create a queue of ints*/
  queue<int> my_queue;
  if (my_queue.empty())
  {
    cout << "Initially the queue will be empty" << endl;
  }

  cout << "Queue size: " << my_queue.size() << endl;
  cout << "insert elements 1,2,3,4,5" << endl;

  for (int i = 1; i < 6; i++) {
    my_queue.push(i);
    std::cout << "New size: " << my_queue.size() << '\n';
  }

  std::cout << "WARNING: POP METHOD RETURNS NULL" << '\n';

  while(!my_queue.empty()) {
    std::cout << "poping elements: " << my_queue.front() << '\n';
    my_queue.pop();
  }

  return 0;
}
