 /************************************************
* print string -- Print a simple string. *
************************************************/
#include <iostream>
#ifdef FIXED
// here the str is a pointer, while the std in sub is a array
extern char *str; // The string to print
int main()
{
  std::cout << str << std::endl;
  return (0);
}
#else
#include "sub.cpp"
extern char str[]; // The string to print
int main()
{
  std::cout << str << std::endl;
  return (0);
}
#endif