#include <iostream>

using namespace std;

typedef struct {
  unsigned char lut;
}lut;

unsigned char LUT[] =
{
  4, // 4b0000
  3, // 4b0001
  2, // 4b0010
  2, // 4b0011
  2, // 4b0100
  1, // 4b0101
  1, // 4b0110
  1, // 4b0111
  3, // 4b1000
  2, // 4b1001
  1, // 4b1010
  1, // 4b1011
  2, // 4b1100
  4, // 4b1101
  4, // 4b1110
  4  // 4b1111
};

int main(void)
{
  int t,n;
  //cin >> t;
  int c_total = 0;
  int c_current = 0;
  int i = 0;
  int last = 0;

  cin >> n;
  cout << "Test input: " << n << endl;
  /* unless is all 1's the minumum is 1 */
  if(n >= 0xFFFFFFFF){
    cout << 0 << endl;
    return 0;
  }

  while(32 > i)
  {
    if((n & 0x01) == 0)
    {
      if(last == 0)
      {
        c_current = (c_current == 0 && i > 0)? 2:c_current+1;
        if (c_total < c_current)
        {
          c_total = c_current;
        }
      }
      last = 0;
    }
    else
    {
      c_current = 0;
      last = 1;
    }
    n >>= 1;
    i++;
  }
  cout << c_total << endl;
  return 0;
}
