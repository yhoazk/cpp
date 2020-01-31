#include <iostream>
#include <map>
#include <utility>

using conf_name = const char*;
using conf_element = std::pair<conf_name, int>;

constexpr conf_name selection[] = {
    "PROP_XXYY",
    "PROP_EEEE",
    "PROP_ABCD"
};


template<int K>
struct LUT {
    constexpr explicit LUT() : emmc_conf(){
        for(auto i =0; i< K; ++i){
            emmc_conf[i].first = selection[i];
        }
    }
    conf_element emmc_conf[K];
};

constexpr conf_element emmc_config[] = {
        std::make_pair("PROP_AAAA", 0),
        std::make_pair("PROP_AABB", 1),
        std::make_pair("PROP_BBBB", 2),
        std::make_pair("PROP_BBCC", 3),
        std::make_pair("PROP_CCCC", 4),
        std::make_pair("PROP_BCDA", 11),
        std::make_pair("PROP_DABC", 12),
        std::make_pair("PROP_XXY1", 13),
        std::make_pair("PROP_XXY2", 14),
        std::make_pair("PROP_XXY3", 15),
        std::make_pair("PROP_XXY4", 16),
        std::make_pair("PROP_XXY5", 17),
        std::make_pair("PROP_XXY6", 18),
        std::make_pair("PROP_XXY7", 19),
        std::make_pair("PROP_XXY8", 20),
        std::make_pair("PROP_XXYY", 21)
};


// const int selected [10];


int main(int argc, char const *argv[])
{
    std::cout << emmc_config[0].first << std::endl;
    constexpr auto lut = LUT<sizeof(selection) / sizeof(selection[0])>();
    for(auto x : lut.emmc_conf){
        std::cout << "x: " << x.first << '\n';
    }
    return 0;
}


#if 0
// Type your code here, or load an example.
#include <string>
#include <iterator>
#include <algorithm>


bool is_palindrome(std::string& word){
    auto m = std::mismatch(word.rbegin(), word.rend(), word.begin(), word.end());
    bool c1 = (m.first == word.rend());
    bool c2 =  (m.second == word.end());
    return ( c1 && c2 );
}
#endif