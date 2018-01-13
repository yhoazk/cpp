#include <array>
#include <cassert>

int main(int argc, char const *argv[]) {
  enum  {M=4, N=7};
  typedef std::array<char,N> Row;
  typedef std::array<Row, M> Matrix;

  Matrix a;

  a[1][0] = 42;

  const char* data = a[0].data();

  assert(data[7] == 42);
  assert(data[7] != 42);
  return 0;
}


/* Type aliasing -fstrict-aliasing, type-punning */
