/*
 * Demo using ltrace to get malloc, free traces
 * */

#include <iostream>
#include <vector>
#include <array>
#include <functional>
#include <set>
#include <thread>

/*
 * bazel helps with the command --run_under=ltrace
 * bazel run --run_under=ltrace //debug/trace:trace
 * if the command needs to have args, add ''s
 * for ltrace, when multiple systemcalls need to be filtered use + or - to exclude
 * bazel run --run_under='ltrace -e=malloc+free' //debug/trace:trace
 *
 * When several threads need to be traced use
 * bazel run --run_under='ltrace -f -e=malloc+free' //debug/trace:trace
 * */


/*When the array size is too big  this call gives a sigsegv 
 * the V ins sigseg is for segment violation.
 * */
// constexpr size_t array_size{1000000000}; crash
// constexpr size_t array_size{100000000}; crash
// constexpr size_t array_size{10000000}; crash
constexpr size_t array_size{100000}; // works
auto f = std::function<void(void)>([](){
  std::array<double, array_size> arr{};
  std::cout << "Elements in array";
  for(auto& element : arr) {
    element = 5;
    //std::cout << " e: " << element;
  }
});


// arrays only take stack memory: https://stackoverflow.com/questions/39548254/does-stdarray-guarantee-allocation-on-the-stack-only
//
// it can be forced to use heap with new std::array<>

auto s = std::function<void(void)>([](){
    using element_t = std::array<double, 5>;
    std::set<element_t> elements{};
    for (int n = 0; n < 10; ++n) {
        double d = static_cast<double>(n);
        elements.emplace(element_t{d,d,d,d,d});
    }
    std::cout << "Size of set: " << elements.size() << '\n';
});

int main() {
  using namespace std;
  /*vector<int> v;
  for(int k=0; k < 100; ++k) {
    v.push_back(k);
  }
  cout << "Elements in vector: " << v.size() << '\n';
  */
  std::cerr << "calling F\n";
  f();
  std::cerr << "calling s\n";
  s();
  return 0;
}
