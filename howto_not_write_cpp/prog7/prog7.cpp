// The crooked square
// Squares a number
#include <iostream>
int main(int argc, char const *argv[])
{
  int array[5]; // hold the sqs
  int i; // index

  for(i=1; i<5;++i){ // index out of the array
    array[i] = i*i;
  }
  for(i=1;i<5;++i){
    std::cout << i << " Squared is " << array[i] << '\n';
  }
  #if 0
  Still in F26 the ans is
  1 Squared is 1
  2 Squared is 4
  3 Squared is 9
  4 Squared is 16
  5 Squared is 25
  The problem is that the memory gets corrupted after
  the last
  #endif
  return 0;
}

