#include <iostream>
#include <type_traits>
/* Type traints allow to take decisions based on the type of the template
 *  In this example an specialization is made for character members
 *  in which the value is true, but if a template function is used with a
 *  type which is not member it will be false as it will use the default
 *  template
 *  C++11 includes a header with common traits and capabilities.
 *  The header is type_traits, for example:
 *  - is_void
 *  - is_null_pointer
 *  - is_arithmetic
 *  - is_array
 *  - is_enum
 *  - is_signed
 *  - is_unsigned
 *  This type_traits can be used at compile time with the static_assert
 *  but also can be used in run time
 * */

template<typename T>
struct is_char {
  static const bool value = false;
};

// Use a specialization 
template<>
struct is_char<char> {
  static const bool value = true;
};


template<>
struct is_char<wchar_t> {
  static const bool value = true;
};

// this way anything that is not a char will yield false

template<typename T>
void foo(T data){
  if(is_char<T>::value){
    std::cout << "Is char" << '\n';
  } else {
    std::cout << "Not a char" << '\n';
    if(std::is_floating_point<T>::value){
      std::cout << "Is floating point\n";
    }
  }
}

int main(){
  foo('c');
  foo(3.1435);
  static_assert(!std::is_signed<unsigned>::value); 
  
  return 0;
}
