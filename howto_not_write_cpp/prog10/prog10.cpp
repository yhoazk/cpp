 /************************************************
* divide -- Program to figure out how many *
* digits are printed in floating point *
* by print 1/3 or 0.333333. *
************************************************/
#include <iostream>
int main()
{
  float result; // Result of the divide
  // here the 1 and the 3 are int by default
  // the int division is 0
  //result = 1/3; // Assign result something
  // add the type specifier to fix if
  result = 1.0f/3; // Assign result something

  std::cout << "Result is " << result << '\n';
  return (0);
}