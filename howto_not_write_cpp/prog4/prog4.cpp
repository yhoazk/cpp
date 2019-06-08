// Typical initial problem
// A classic math problem is to add the numbers 1 to 100.
// But tihs program seems to come up with the wrong ans

#include <iostream>

int main(int argc, char const *argv[])
{
  int sum;
  int count;
  for(count = 1; count <= 100; ++count){
    sum+= count;
  }
    std::cout << "count: " << sum << "\n";
  return 0;
}

