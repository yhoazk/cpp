// No comment
// This program computes the area of a triangle
// There is a surprise in the code
//
#if 0
#include <iostream>
int main(int argc, char const *argv[]){
  int base = 0;
  int height = 0;

  base = 5;
  height = 2;
  // using ints in division?
  int area = (base * height) / 2;
  std::cout << "The area is " <<
   area << std::endl;
  return 0;
}
#endif

 /************************************************
 * triangle -- Compute the area of a triangle *
 ************************************************/
#include <iostream>
int main()
{
int base = 0; /* Base of the triangle */
int height = 0; /* Height of the triangle */
 base = 5; /* Set the base of the triangle
 height = 2; /* Set the height */
// missing  end of comment
 // Area of the triangle
 int area = (base * height) / 2;

 std::cout << "The area is " <<
 area << std::endl;
 return (0);
}

