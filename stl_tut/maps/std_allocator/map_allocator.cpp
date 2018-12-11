#include <iostream>
#include <map>
// this sample fails with new versions of libc. 
template <typename key, typename value, typename cmp = std::less<key>, typename alloc = std::allocator<std::pair<key, value> > >
using my_map = std::map<key, value, cmp, alloc>;
int main(int argc, char const *argv[])
{
  /* code */

  my_map<int, int> m;
  m.insert(std::make_pair<int,int>(3,52));
  std::cout << m[3] << std::endl;
  return 0;
}
