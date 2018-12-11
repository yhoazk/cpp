#include <memory>
#include <iostream>

class [[deprecated]] flaky{
  private:
    int o{0};
};


using namespace std;
int main(){
  std::unique_ptr<int> p(new int);
  volatile flaky f;
  *p = 11;
  auto y = [p = std::move(p)](){cout << "inside: " << *p << '\n'; };
  y();
  cout << "outside: " << *p << '\n';
  return 0;
}

