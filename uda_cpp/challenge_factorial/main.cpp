#include <iostream>
//#include "./Factorial.h"
int Factorial(int n)
{
    if(n == 1)
        return 1;
    else
        return n * Factorial(n-1);
}
int main()
{
    // feel free to change this test case!
    int value = Factorial(24);
    std::cout << "6! should equal 720. Your Factorial method returned:" << std::endl;
    std::cout << value << std::endl;
}

