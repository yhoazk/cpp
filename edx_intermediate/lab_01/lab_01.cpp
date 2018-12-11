#include <iostream>


void PassByValue(int in)
{
  std::cout << "In function PassByValue" << std::endl;
}
int main(int argc, char const *argv[]) {
  int num1 = 3;
  int* pNum = &num1;
  *pNum=5;

  PassByValue(num1);

  return 0;
}
