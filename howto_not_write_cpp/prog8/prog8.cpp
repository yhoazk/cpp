// Mad character
// tries to check out how to use if statements with
// char vars
#include <iostream>
int main(int argc, char const *argv[]){
  char ch;
  ch = 0xFF;
  // here we are assuming that 0xFF is a signed type
  // this means that 0xff when converted to int for the
  // comparison below get the vale of 0xffff_ffff
  if(0xFF == ch){
    std::cout << "Succs\n";
  } else {
    std::cout << "Fails\n";
  }
  // This operation does what we intend, but the solution
  // is to not use char for numerical comparisons
  if(static_cast<char>(0xFF) == ch){
    std::cout << "Succs\n";
  } else {
    std::cout << "Fails\n";
  }
  return 0;
}

