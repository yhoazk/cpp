#include <thread>
#include <iostream>
#include <chrono>

void my_thread_func()
{
    std::cout<<"hello"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main()
{
    std::thread t(my_thread_func);
    t.detach();
    return 0;
}
