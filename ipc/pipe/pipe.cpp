#include <iostream>
#include <chrono>
#include <array>
#include <unistd.h>

#include <thread>

enum operation {
    ADD = 0,
    MUL = 1,
    DIV = 2,
};

struct action {
    operation op;
    double operand_a;
    double operand_b;
    double result;
};

void resolver (int pipefd) {
    std::cerr << __func__ << ::getpid() << std::endl;
    int limit{10};
    int val;
    while (limit--) {
        ::read(pipefd, &val, sizeof(val));
        std::cerr << "Val: " << val << std::endl;
    }
    close(pipefd);
    std::cerr << "Ending: " << __func__ << std::endl;
}

void creator (int pipefd) {
    using namespace std::chrono_literals;

    std::cerr << __func__ << ::getpid() << std::endl;
    int limit{50};
    while (limit-- > 40) {
        ::write(pipefd, &limit, sizeof(limit));
        std::this_thread::sleep_for(100ms);
    }
    close(pipefd);
    std::cerr << "Ending: " << __func__ << std::endl;
}


int main () {
    std::array<int,2> pipes{{-1, -1}};
    auto res{::pipe(&pipes[0])};
    if (res == -1) {
        std::cerr << "Error opening pipes" << std::endl;
    } else {
        std::cerr << "Pipes open" << std::endl;
        
        auto fork_res{fork()};
        if (fork_res != 0) {
            resolver(pipes[0]);
        } else {
            creator(pipes[1]);
        }
    }
    return 0;
}
