/* The vector container type is similar to an array, but
  it takes care of the storage in case it grows.

  Vectors are sequence of containers representing arrays
  that can change in size. Just like arrays use contiguous
  storage locations for their elements, this means that the elements
  can also be accessed by pointers and offsets.
  The main diference between a vector and an array.

  As the vectors can grow and the contiguous location condition has to be met
  sometimes is necessary to reallocate in order to grow. Vectors do not allocate
  the space each time an element is inserted, instead allocate some extra space
  for possible growth, and then the container may have a larger space than the
  stricly needed to contain its elements.

  Then vectors consume more memory than arrays in order to manage the grow in a
  more efficient way.


  Compared to other sequence containers ( deque, list and forward_list) vectors
  are very efficient in accessing the elements ( the same as arrays) and
  relatively efficient in adding or removing elements at the ends of the storage.
  When the operation requires to add elements in the middle of the storage
  vectors perform worse than other sequence containers.

 */
#include <iostream>
#include <vector>





bool insert_n_elemets(size_t n, int val[], std::vector<int> &v)
{
  bool result = true;
  for (size_t i = 0; i < n; i++) {
    v.push_back(val[i]);
  }
  return (true);
}


bool print_n_values(size_t n, std::vector<int> &v)
{
  bool result = true;

  for (size_t i = 0; i < n; i++) {
    std::cout << v[i] << std::endl;
  }

  return(result);
}

/*****************************************/
/***** VECTOR Iterators  *****************/
/*****************************************/


/**
  The begin member function:
  returns an intreator to the first element of the
  vector
*/
bool iterate_in_vector(std::vector<int> &v)
{
  for (std::vector<int>::iterator i = v.begin(); i != v.end() count; ++i) {
    /* code */
  }

}




int vals[] = {1,2,3,5,4,2,2};

int main(int argc, char const *argv[]) {
  std::vector<int> v;
  insert_n_elemets(6, vals, v);
  /**
    Vector methods
    front()
    Retrns a direct reference to the first element in the Vector.
    The element is not removed from the vector.
  */
  std::cout << v.front() << std::endl;
  std::cout << v.front() << std::endl;
  std::cout << v.front() << std::endl;
  /**
    Vector methods
    size()
    Returs the size of the vector, ie the number of <T>
    elements contained
  */

  std::cout << "The vector cointais " << v.size() << " elements." << std::endl;
  /**

  */

  //print_n_values(6, v);
  return 0;
}
