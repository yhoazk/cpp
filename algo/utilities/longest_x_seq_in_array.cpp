/*
Utility which returns the index and the length in an array where the longest
sequence of the element n occurs.

This algorithm fails if there are no sequences, i.e. spread elements, it returns
0 length if there are no sequences
complexity O(n)
size O(1)
*/

#include <iostream>

using namespace std;





size_t test_arr[] = {
  1,
  1,
  5,
  4,
  3,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  8,
  7,
  8,
  7,
  8,
  9,
  9,
  9,
  9,
  9,
  4,
  55
};

bool find_longest_seq(size_t* array, size_t depth, size_t to_find, size_t &MaxLength, size_t &start_index)
{
  size_t max_len = 0;
  size_t seq_start = 0;
  size_t current_len = 0;
  bool last_is_equal = false;

  for(size_t i=0; i<depth; ++i)
  {
    if(to_find == array[i])
    {
      ++current_len;
      if(max_len < current_len)
      {
        seq_start = i;// this cover the case when there's only 1 element
        max_len = current_len;

        if(last_is_equal)
        {
          /* There are consecutive elements */
          seq_start = i - current_len+1; /* plus 1 as the i   */
        }
      }
      last_is_equal = true;

    }
    else
    {
      current_len = 0;
      last_is_equal = false;
    }
  }

  MaxLength = max_len;
  start_index = seq_start;

  return true;
}

int main(void)
{
  size_t len = 0;
  size_t index_inarray = 0;
  size_t x = 8;
  find_longest_seq(test_arr, sizeof(test_arr)/sizeof(test_arr[0]),x,  len, index_inarray);
  cout << "longest sub array:\nLongest sequence of: " << x << " is " <<len << " at position: "<< index_inarray << endl;

}
