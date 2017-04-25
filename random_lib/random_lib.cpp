#include <iostream>
#include <random>
#include <functional>

int main(int argc, char** argv)
{
    std::cout << argc << std::endl;
    int lb = (int)(*(char*)argv[1]);
    std::cout << lb << std::endl;
    std::default_random_engine gen;
    std::uniform_int_distribution<int> uniform_dist(1,6);

    auto dice = std::bind( uniform_dist, gen);
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    std::cout << dice() << std::endl;
    return 0;
}

