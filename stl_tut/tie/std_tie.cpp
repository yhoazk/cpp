#include <bits/stdc++.h>

class dummy{
public:
    dummy(const unsigned int id): int_val(id), bool_val(false) {
        std::cout << "dummy born: " << int_val << '\n' ;
    }

    ~dummy(){
        std::cout << "dummy dead: " << int_val << '\n';
    }
    //cpy constructor
    dummy(const dummy& obj){
        std::cout << "Cpy ctor of: " << int_val;
        std::cout << " From " << int_val << " To: " << obj.int_val << '\n';
        int_val = obj.int_val;
    }
    unsigned int int_val{0};
    bool bool_val{false};

};


int main(int argc, char** argv){
    auto tup = std::make_pair(1, "Test");
    std::cout << tup.first;
    std::cout << tup.second;

    // To unpack the tuple
    size_t k;
    std::string s;
    std::tie(k, s) = std::make_pair(1ul, "Test");
    std::cout << '\n' << k;
    std::cout << '\n' << s;
    // If a value is not of interes, we can use std::ignore
    // there are no effects on the 2nd element
    std::string t;
    std::tie(std::ignore, t) = std::make_pair(1ul, "Test");
    std::cout << "\nT val: " << t << std::endl;

    // Is the destructor of a std::ignored object called??
    {
        dummy d1{1};
        dummy d2{2};
        dummy da{3};
        dummy db{4};
        dummy dc{5};
        // which constructor is called?
        std::tie(da,db) = std::make_pair(dummy{6}, dummy{7});

        std::cout << "Call std::ignore" << std::endl;
        std::tie(std::ignore,dc) = std::make_pair(dummy{8}, dummy{9});
        std::cout << "leaving fake scope" << std::endl;
    }
    return 0;
}