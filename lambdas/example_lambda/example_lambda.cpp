#include <iostream>

using namespace std;

/*
 * Syntax = [](){}
 * [] <- capture
 *  - [a,&b] = capture a by copy and b by referene
 * () <- params
 * - WHAT IS THE DIFFERENE BETWEEN CAPTURE AND PARAMETER?
 * {} <- body
 * */
auto k = [](){ return 5<6; };
int main()
{
  cout << k() << '\n';
  return 0;
}
