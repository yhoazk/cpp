#include <iostream>
#include <array>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>
#include <boost/circular_buffer.hpp>

/* Implement a median filter with:
 * - the naive approach
 * - the using a priority queue to avoid sorting the array each time
 * - with the result of reading the paper: 
 */

template<typename data_type_t>
struct naive {
  boost::circular_buffer<data_type_t> data;
  naive(size_t window_size) {
    data.resize(window_size);
  }
  //template<typename data_type_t, typename data_container_t>
  data_type_t naive_median(const data_type_t sample) {
    std::cout << "data size: " << data.size() << std::endl;
    data.push_back(sample);
    std::sort(std::begin(data), std::end(data));
    return data.get(4);
  }
};

int main (int argc, char** argv, char** env) {
  std::cout << "OKKO" << std::endl;
//   std::array<double, 10> data{1,2,3,4,5,6,7,8,9,1};
  naive<double> naiv{9};

  std::cout << naiv.naive_median(9.0f) << std::endl;

  return 0;
}