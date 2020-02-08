#include <iostream>
#include "calc.h"

int main(){
    {
        basic_math bc;
        std::cout << bc.addition(9,9) << '\n';
        std::cout << bc.multiply(9,9) << '\n';
        std::cout << bc.divide(91,9) << '\n';
        std::cout << bc.addition(119,19) << '\n';
    }
    return EXIT_SUCCESS;
}
