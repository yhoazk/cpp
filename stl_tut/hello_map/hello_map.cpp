#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <exception>
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


void init_map(void)
{
  map<string, int > v = {{"one",1},{"two",2},{"three",3},{"four",4}};
  /* Insert unnamed vectors in the map */

  std::cout << "v['one']: " << v["one"] <<  std::endl;
  std::cout << "v['two']: " << v["two"] <<  std::endl;
  std::cout << "v['three']: " << v["three"] <<  std::endl;
  std::cout << "v['four']: " << v["four"] <<  std::endl;
  std::cout << "Delete elements by key:" << "\n\n";

  std:: cout << "When a map is indicated to return a value of an unknown key it adds the key to the map and attaches null as \n its value, without trowing an exception\n";
  std::cout << "v.erase('one')" << std::endl;
  v.erase("one");
  try{
    std::cout << v["ddddone"] << " - Map size: " << v.size() << std::endl;
    std::cout << v["ddddoneffff"] << " - Map size: " << v.size() << std::endl;
    std::cout << v["ddddonefff"] << " - Map size: " << v.size() << std::endl;
    std::cout << v["ddddonffff"] << " - Map size: " << v.size() << std::endl;
    std::cout << v["dddddsdsoneffff"] << " - Map size: " << v.size() << std::endl;

    std::cout <<  "So if we are trying to probe that a map has certain key we must use the map::count() function.\n this function returns the count of elements with an equivalent key\n ";
  }
  catch(exception&   e)
  {
    std::cout <<  "Catched exception: " <<  e.what() << std::endl;
  }
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
  init_map();
  return 0;
}
