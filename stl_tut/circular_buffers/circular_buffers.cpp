/* Performance test of vector vs deque as circular buffers */

#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
using timestamp_pair = std::tuple<uint64_t, uint64_t>;

/* Insert and remove items from a container-like object */
template<typename container>
void test(container& buffer) {
    timestamp_pair p_ts{0,0};
    size_t n{10};
    while(n>0){
        buffer.push_back(std::make_pair<size_t,size_t>(0,n--));
        std::cout << "Pussing\n";
        buffer.pop_back();
    }
}


int main(int c, char** v, char** env) {
    std::vector<timestamp_pair> v_buffer{};
    std::deque<timestamp_pair> dq_buffer{};
    std::cout << "Test vector\n";
    test(v_buffer);
    std::cout << "Test deque\n";
    test(dq_buffer);

    return 0;
}