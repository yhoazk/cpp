#include <iostream>
#include <vector>


class multi {

  private:
  union {
    size_t _size_t;
    double _dbl;
    std::vector<unsigned char> _byte_array; // where will this be destroyed?
  };

  public:
  explicit multi(const size_t s): _size_t(s){  }

  explicit multi(const double d): _dbl(d) {}

  explicit multi(void* data, const size_t len): _byte_array(){
    unsigned char* data_as_char = static_cast<unsigned char*>(data);
    _byte_array.reserve(len);
    for(size_t i = 0; i < len; i++)
    {
      _byte_array.push_back(data_as_char[i]);
    }

  }

  size_t get_size(){
    return _byte_array.size();
  }


  #ifdef LEAK
  ~multi(){}
  #else
  ~multi(){
    _byte_array.clear(); // free allocated objects
    _byte_array.resize(0); // change the size
    _byte_array.shrink_to_fit(); // change the capacity
  }
  #endif
};


void test_multi(void){
  std::vector<char> test_data = {'x', 'y', 'z'};
  multi T(static_cast<void*>(&test_data[0]), test_data.size());
  std::cout << "size is: " << T.get_size() << '\n';
}

int main(){
  std::cout << "w" << std::endl;
  test_multi();
  test_multi();
  test_multi();
  test_multi();

  return 0;
}
