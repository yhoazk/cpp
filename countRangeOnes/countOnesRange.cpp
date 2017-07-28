#include <iostream>
using namespace std;
//https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html

size_t getLeftMost(size_t x)
{
    size_t c = 0;
    while(x)
    {
        x >>=1;
        c++;
    }
    return c;
}

size_t getOnesFromZeroToN(size_t n)
{
    unsigned int bits = 8*sizeof(size_t);
// int pos = n ^ (n&(n-1)); <- this gets the rigth most bit set
    size_t c = getLeftMost(n);
    cout << "leftmost: " << c << endl;
//    size_t x = (1 << c) -1; /* integer filled of 1s */
    size_t sum = 0;
    while(c)
    {
        if((size_t)0x0 != (n&(1<<c)))
        {
            sum += (1 << (c-1)) * c;
            cout << '1';
        }
        else
        {
            cout << '0';
        }
        --c;
    }
    cout << endl;
    return sum;
}


size_t countRangeOnes(int l, int r)
{

}


int main(void)
{
    size_t k = 1589;
    cout << "most left count of " << k << " is " << getLeftMost(k) << endl;
    cout << "one count of " << k << " is " << getOnesFromZeroToN(k) << endl;
    return 0;
}
/*
1111 0000 0001 0111 1111
1111 0000 0001 0111 111
//http://coub.com/view/spoap
//
//
0010 0111 <- cien

left most: 6
0001 1111 : 80
0000 1111 + 0*32
0000 0111 + 1 * 12
0000 0011 + 1 * 4
0000 0001 + 1 * 1


+ self bit count

0010 1000

0010 0111
----------
0001 1111 : 80   == 80 + 12 + (7+1)
0000 1111 : 32*0
0000 0111 : 12*1
0000 0011 : 4*1
0000 0001 : 1*1


0011 0100 : 143
  || |||\_ 1
  || ||\__ 4
  || |\___ 12
  || \____ 32
  |\______ 80
  \_______ 192  = 192 - 32 - 4 -1


-------
0011 1111 : 192 - 80 -12-4 zeros
0001 1111 : 80
0000 1111 : 32*1
0000 0111 : 12*1
0000 0011 : 4*1
0000 0001 : 1*0

-----------------------------------
0000000
0000001
0000010
0000011_______4
0000100
0000101
0000110
0000111_______
0001000
0001001
0001010
0001011
0001100
0001101
0001110
0001111______
   |||\_____8
   ||\______8
   |\_______8
   \________8

0010000
0010001
0010010
0010011
0010100
0010101
0010110
0010111
0011000
0011001
0011010
0011011
0011100
0011101
0011110
0011111_____
  ||||\_____8+8
  |||\______8+8
  ||\_______8+8
  |\________8+8
  \_________8+8


0100000
0100001
0100010
0100011
0100100
0100101
0100110
0100111______cien
0101000
0101001
0101010
0101011
0101100
0101101
0101110
0101111
0110000
0110001
0110010
0110011
0110100--x
0110101
0110110
0110111
0111000
0111001
0111010
0111011
0111100
0111101
0111110
0111111_________ciento noventa y dos
1000000
1000001
1000010
1000011
1000100
1000101
1000110
1000111
1001000
1001001
1001010
1001011
1001100
1001101
1001110
1001111
1010000
1010001
1010010
1010011
1010100
1010101
1010110
1010111
1011000
1011001
1011010
1011011
1011100
1011101
1011110
1011111
1100000
1100001
1100010
1100011
1100100





1589 

0110 0011 0101 =    1111111111 = 1023
                    0111111111 = 511
                    0000011111 = 31
                    0000001111 = 15
                    0000000111 = 7
                    0000000001 = 1
                    0000000000 + 1



// 
//
*/
