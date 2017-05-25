#include <iostream>
#include <cstring>
using namespace std;


void myMemCpy(void* dst, void* src, size_t num)
{
  size_t* l_dst = (size_t*)dst;
  size_t* l_src = (size_t*)src;
  char* c_dst = (char*)dst;
  char* c_src = (char*)src;

  while (num >= sizeof(size_t)) {
    /* code */
    *l_dst++ = *l_src++;
    num -= sizeof(size_t);
  }
  while (num > 0) {
    *c_dst++ = *c_src++;
    --num;
  }
}


size_t test_arr[] = {9,8,7,6,5,4,3,2,1,0};

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
    myMemCpy(tmp, &pArray[(lenOfArray-shift)], shift*sizeof(size_t));
    myMemCpy(&pArray[shift], pArray, (lenOfArray-shift)*sizeof(size_t));
    myMemCpy(pArray,tmp,shift*sizeof(size_t));
  }
  else
  {
    myMemCpy(tmp, pArray, shift*sizeof(size_t));
    myMemCpy(pArray, &pArray[shift], (lenOfArray-shift)*sizeof(size_t));
    myMemCpy(&pArray[lenOfArray-shift], tmp, shift*sizeof(size_t));
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
