#include <iostream>
/**
 * What will be printed?
 * The correct answer is
 * 0
 * 0
 * 0
 * and then
 * 0
 * 1
 * 2
 * The increment is done after the return
 * */
int first(void){
  int i = 0;
  return(i++);
}

int second(void){
  static int i = 0;
  // Here the value is saved and then incremented
  // the saved value is then returned
  return(i++);
}

int main(){

  for (size_t counter = 0;  counter  < 3;  counter++){
    std::cout << "First: " << first() << "\n";
  }
  for (size_t counter = 0;  counter  < 3;  counter++){
    std::cout << "Second: " << second() << "\n";
  }

}