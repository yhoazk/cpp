#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

constexpr size_t N_WORKERS(10);
constexpr size_t MESSAGES_PER_WORKER(20);
std::vector<std::thread> workers; // do not predefine the size of the 
// threads, by doing that the ctor is not called at the correct place
// with the correct paramenters

void log_worker(size_t idx){
    std::cout << idx;
    size_t messages = MESSAGES_PER_WORKER;
    while(messages--){
        std::cout << "thid:" << idx << " N: " << messages << '\n';
    }
}


int main(int argc, char const *argv[])
{
    
    for(size_t i=0; i < N_WORKERS; i++){
        workers.push_back(std::thread(log_worker, i));
    }
    
    for(auto& th : workers){
        th.join();
    }
    return 0;
}
