#include <iostream>
#include <memory>
/* Here we will have an error at compile time as the copy constructor was 
 * deleted from the base obj
 * */

int main(){
    std::unique_ptr<int> a(new int);
    a = a;
    return 0;
}
