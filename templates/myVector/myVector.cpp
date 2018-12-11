#include <iostream>

using namespace std;

template <class T>
class myVector
{
private:
  size_t capacity;
  size_t size;
  T* buffer;

public:
  myVector(): capacity(0), size(0){ std::cout << "Empty Constructor" << '\n';};
  myVector(size_t new_size): size(new_size), capacity(new_size<< 1U), buffer(new T[new_size])
  {
    std::cout << "Size constructor" << '\n';
    /* Get twice as much capacity to not allocate each time a new element is added */
    // capacity = new_size << 1U;
    // buffer = new T[capacity];
    /**/
  }


  ~myVector()
  {
    delete [] buffer;
  }
  myVector(size_t new_size, const T& default_value)
  {
    std::cout << "fill with constructor" << '\n';
    size = new_size;
    /* Get twice as much capacity to not allocate each time a new element is added */
    capacity = capacity << 1U;
    buffer = new T[capacity];
    for (size_t i = 0; i < capacity; i++)
    {
      buffer[i] = default_value;
    }
  }

  void push_back(const T& element)
  {
    if (capacity < size || size == capacity) {
      /* increment the reserved space for this vector */
      reserve((capacity+1) << 1);
    }
      buffer[size++] = element;
  }

  size_t get_size (void)
  {
    return this->size;
  }

  void reserve(size_t new_capacity)
  {
    std::cout << "reserve" << '\n';
    T* new_buffer = new T[new_capacity];
    /* Copy the contentes from the old buffer into the new one */
    for (size_t i = 0; i < capacity; ++i) {
      new_buffer[i] = this->buffer[i];
    }
    /* Delte the old buffer */
    delete [] this->buffer;
    /* update this object variables */
    capacity = new_capacity;
    this->buffer = new_buffer;
  }

  T& operator[](size_t indx)
  {
    if (indx < size)
    {
      return buffer[indx];
    }
  }
};


void test_printAll(myVector<int>& v)
{

}
void test_fillAll(myVector<int>& v, int k)
{
  for (size_t i = 0; i < v.get_size(); i++) {
    /* code */
    v.push_back(k);
  }
}

void test_pushN(myVector<int>& v, int n, int k) {
  /* code */
}

int main(int argc, char const *argv[]) {

  myVector<int> test_empty;
  myVector<int> test_size(24);
  myVector<int> test_fillWith(5,34);

  std::cout << "Print size Empty: " << test_empty.get_size() << '\n';
  std::cout << "Print size size: " << test_size.get_size() << endl;
  std::cout << "Print size test_fillWith: " << test_fillWith.get_size() << '\n\n';

  std::cout << "Print Elements: " << test_size[0] << '\n';
  test_size[0] = 0;
  std::cout << "Print Elements: " << test_size[0] << '\n';

  std::cout << "Print Elements: " << test_fillWith[0] << '\n';
  std::cout << "push back" << '\n';
  test_empty.push_back(12);
  test_empty.push_back(13);
  test_empty.push_back(15);
  std::cout << "Print size Empty: " << test_empty.get_size() << '\n';







  return 0;

}
