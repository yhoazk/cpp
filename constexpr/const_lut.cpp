#include <iostream>
#include <cstring>
#include <map>
#include <utility>

using conf_name = const char*;
using conf_element = std::pair<conf_name, int>;
// what happens in the case when the string is not found at compile time?
constexpr std::array<conf_name, 3> selection {{
    "PROP_XXYY",
    "PROP_CCCC",
    "PROP_AAAA"
}};

constexpr std::array<conf_element, 16> emmc_config {{
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
}};

template<int K>
struct LUT {
    constexpr explicit LUT() : emmc_conf(){
        for(auto i =0; i< K; ++i){
            for(size_t n = 0; n < emmc_config.size(); ++n){
                if(std::strcmp(selection[i] , emmc_config[n].first)==0) {
                    emmc_conf[i].first = emmc_config[n].first;
                    emmc_conf[i].second = emmc_config[n].second;
                }
            }
        }
    }
   // constexpr static  std::array<conf_element, K> emmc_conf;

    conf_element emmc_conf[K];
};



// const int selected [10];

//optional tuple_size 
int main(int argc, char const *argv[])
{
    //constexpr auto lut = LUT<std::tuple_size<selection>::value()>();
    constexpr auto lut = LUT<selection.size()>();
    //static_assert(lut.emmc_conf.size());
    for(auto x : lut.emmc_conf){
        std::cout << "x: " << x.first << " val:" << x.second << '\n';
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
