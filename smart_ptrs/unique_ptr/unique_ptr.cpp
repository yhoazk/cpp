#include <iostream>
//#include <memory>

int main(){
    std::unique_ptr<int> a(new int);
    a = a;
    return 0;
}
