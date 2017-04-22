#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;


void map_of_vectors(void)
{
  map<char, vector<int> > v;
  /* Insert unnamed vectors in the map */
  v['a'] = std::vector<int>(5);
  v['b'] = std::vector<int>(3);
  v['c'] = std::vector<int>(1);

  std::cout << "v['a'].size(): " << v['a'].size() <<  std::endl;
  std::cout << "v['b'].size(): " << v['b'].size() <<  std::endl;
  std::cout << "v['c'].size(): " << v['c'].size() <<  std::endl;

}


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

map_of_vectors();

  return 0;
}
