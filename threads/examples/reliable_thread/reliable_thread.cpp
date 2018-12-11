#include <thread>
#include <iostream>

void my_thread_func()
{
    std::cout<<"hello"<<std::endl;
}

int main()
{
    std::thread t(my_thread_func);
    t.join(); // without this join the thread will die w/o exeption, but with error
    return 0;
}
