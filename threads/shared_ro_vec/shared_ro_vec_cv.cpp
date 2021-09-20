/*!
 * Undefined behaviour for handling a signal while the thread is under sleep
 */

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <optional>
#include <csignal>
#include <atomic>

extern "C" {
    #include <unistd.h>
}

std::atomic_bool dump{false};
std::atomic_bool done{false};
constexpr size_t min_len{5};

template<typename chrono_t>
struct prod {
    prod(std::vector<chrono_t>& vec) : samples_vec{vec} {}

    int do_prod() {
        samples_vec.push_back(chrono_t{5});
        if (samples_vec.size() >= min_len) {
            return 1;
        }
        return 0;
    }

    std::vector<chrono_t>& samples_vec;
};


template<typename chrono_t>
struct cons {
    cons(const std::vector<chrono_t>& vec) : samples_vec{vec} {}

    void copy() {
        std::cout << "SVEC samples: " << std::to_string( samples_vec.size() )<< std::endl;
        for (const auto& sample : samples_vec ) {
            std::cout << "Sample: " << std::to_string(sample.count()) << std::endl;
        }
    }

    const std::vector<chrono_t>& samples_vec;
};

void signal_handler(int sig_no) {
    std::cout << "signal" << std::endl;
    switch (sig_no) {
        case SIGUSR1:
            if (dump) {
                std::cout << "dump true" << std::endl;
                dump = false;
            } else {
                std::cout << "dump false" << std::endl;
                dump = true;
            }
        break;
    }
}

void signal_handler_done(int sig_no) {
    std::cout << "dump false" << std::endl;
    done = true;
}

template<typename chrono_t>
void produce(prod<chrono_t>& p) {
    while (not done) {
        std::this_thread::sleep_for(std::chrono::milliseconds{5000});
        std::cout << "Prod" << std::endl;
        p.do_prod();
    }
    std::cout << "prod done" << std::endl;
}

template<typename chrono_t>
void consume(cons<chrono_t>& c) {
    while (not done) {
        std::this_thread::sleep_for(std::chrono::milliseconds{4000});
        if (dump) {
            std::cout << "Coons" << std::endl;
            c.copy();
        }
    }
    std::cout << "Cons done " << std::endl;
}


int main () {
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler_done);
    std::vector<std::chrono::seconds> shared_samples;
    prod<std::chrono::seconds> p{shared_samples};
    cons<std::chrono::seconds> c{shared_samples};
    std::thread prod_th(produce<std::chrono::seconds>, std::ref(p));
    std::thread cons_th(consume<std::chrono::seconds>, std::ref(c));
    std::cout << "Main PID: " << std::to_string(getpid()) << std::endl;
    while(not done) {
        std::this_thread::sleep_for(std::chrono::milliseconds{3000});
        std::cout << "." << std::endl;
    }
    prod_th.join();
    cons_th.join();
    return 0;
}

