#include <bits/stdc++.h>
/* The insertion sort starts with the trivial case where a list of a single element
 * is sorted. And then grows to all the elements keeping the order of the list 
 * taking the next element and find its place and keeping the order.*/


using namespace std;

std::vector<size_t> test_data = { 0,32,4,2,3,6,8,5,90,9, 1};
std::array<float,11> test_float = { 0.22,3.2,3.44,2.3334,0.03,56.6,800.8,5.0,9.1000,9000, 1.145};
// naive insertion sort
auto pv = [&](auto data){
    for(auto& n : data){
        std::cout << n << " ";
    }
    std::cout << '\n';
};
template<typename T>
void ins_sort(T& v){
    //std::cout << v.size() << '\n';
    for(auto i = std::begin(v); i != std::end(v)-1; ++i){
        // First element is the trivial sorted list
        auto j = i+1; 
        while(j != std::begin(v)+1){
            pv(v);
            if(*j < *(j-1)){
                std::iter_swap(j-1,j);
            }else{
                break;
            }
            --j;
        }
        if(*j < *(j-1)){
            std::swap(i,j);
        }
    }
}

//http://sortbenchmark.org/

int main(void)
{
    //pv();
    ins_sort(test_data);
    std::cout << "--------------------------\n";
    ins_sort(test_float);
    return 0;
}
