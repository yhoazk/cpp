#include <thread>
#include <iostream>

void my_thread_func()
{
    std::cout<<"hello"<<std::endl;
}

int main()
{
    std::thread t(my_thread_func);
    return 0;
}
