#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  map<char, string> map_test;

  map_test['a'] = "abbe";
  map_test['b'] = "beto";
  map_test['c'] = "colo";
  map_test['d'] = "dedo";

  std::cout << "map_test[a]: " << map_test['a']  <<  std::endl;
  std::cout << "map_test[b]: " << map_test['b']  <<  std::endl;
  std::cout << "map_test[c]: " << map_test['c']  <<  std::endl;
  std::cout << "map_test[d]: " << map_test['d']  <<  std::endl;
  std::cout << "map_test contains" << map_test.size() << " elements." <<  std::endl;
  return 0;
}
