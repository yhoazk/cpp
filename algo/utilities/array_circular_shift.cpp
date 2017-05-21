#include <iostream>
#include <cstring>
using namespace std;


size_t test_arr[] = {0,1,2,3,4,5,6,7,8,9};

void printArray(size_t* arr, size_t len)
{
  while (len--)
  {
    cout <<"arr[" << len << "] = " << arr[len] << endl;
  }
}


void circular_shift(size_t* pArray, size_t lenOfArray, signed int shift)
{
  if(shift == 0){ return;}
  size_t* tmp = new size_t[shift];
  shift %= lenOfArray;

  if(shift > 0)
  {
    memcpy(tmp, &pArray[(lenOfArray-shift)], shift*sizeof(size_t));
    memcpy(&pArray[shift], pArray, (lenOfArray-shift)*sizeof(size_t));
    memcpy(pArray,tmp,shift*sizeof(size_t));
  }
  else
  {
    memcpy(tmp, pArray, shift*sizeof(size_t));
    memcpy(pArray, &pArray[shift], (lenOfArray-shift)*sizeof(size_t));
    memcpy(&pArray[lenOfArray-shift], tmp, shift*sizeof(size_t));
  }
  delete[] tmp;
}

int main(void)
{
  cout << "Before shift: \n\n" ;
  printArray(test_arr, sizeof(test_arr)/sizeof(test_arr[0]));
  cout << "\nAfter shift: \n\n" ;
  circular_shift(test_arr, sizeof(test_arr)/sizeof(test_arr[0]), 1);
  printArray(test_arr, sizeof(test_arr)/sizeof(test_arr[0]));
  return 0;
}
