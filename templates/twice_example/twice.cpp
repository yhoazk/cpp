#include <iostream>

template<typename TYPE>
void PrintTwice(TYPE data)
{
    std::cout << "Twice: " << 2* data << std::endl;
}

int main(void)
{
    PrintTwice((int) 5);
    PrintTwice((double) 5.0);
    return 0;
}
