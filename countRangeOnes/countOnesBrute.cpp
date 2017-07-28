#include <iostream>


unsigned char decodeOnes[] = { 
    0,    1,    1,
    2,    1,    2,
    2,    3,    1,
    2,    2,    3,
    2,    3,    3,
    4 };

unsigned int getOnes(unsigned int k)
{
    unsigned int ones =0;
        ones += decodeOnes[((k & (0xf << (7*4))) >> (7*4))]; 
        ones += decodeOnes[((k & (0xf << (6*4))) >> (6*4))];
        ones += decodeOnes[((k & (0xf << (5*4))) >> (5*4))];
        ones += decodeOnes[((k & (0xf << (4*4))) >> (4*4))];
        ones += decodeOnes[((k & (0xf << (3*4))) >> (3*4))];
        ones += decodeOnes[((k & (0xf << (2*4))) >> (2*4))];
        ones += decodeOnes[((k & (0xf << (1*4))) >> (1*4))];
        ones += decodeOnes[(k & 0xf)];
        return ones;
}


unsigned int rangeOnes(unsigned int l, unsigned int r)
{
    unsigned int ones = 0;
    for(;l<=r;)
    {
        ones += getOnes(++l);
        
    }
    return ones;
}


int main()
{

/*
    unsigned int k = 0x22;
    std::cout  << k << "\n";
    std::cout <<(unsigned int)((k&(0xf << (7*4))) >> (7*4)) << std::endl;
    std::cout <<(unsigned int)((k&(0xf << (6*4))) >> (6*4)) << std::endl;
    std::cout <<(unsigned int)((k&(0xf << (5*4))) >> (5*4)) << std::endl;
    std::cout <<(unsigned int)((k&(0xf << (4*4))) >> (4*4)) << std::endl;
    std::cout <<(unsigned int)((k&(0xf << (3*4))) >> (3*4)) << std::endl;
    std::cout <<(unsigned int)((k&(0xf << (2*4))) >> (2*4)) << std::endl;
    std::cout <<(unsigned int)((k&(0xf << (1*4))) >> (1*4)) << std::endl;
    std::cout <<(unsigned int)(k&(0xf)) << std::endl;
    std::cout << "Test getOnes" << std::endl;
    std::cout <<getOnes(0) << std::endl;
    std::cout << "----" << std::endl;
    std::cout <<getOnes(1) << std::endl;
    std::cout << "----" << std::endl;
    std::cout <<getOnes(2) << std::endl;
    std::cout << "----" << std::endl;
    std::cout <<getOnes(3) << std::endl;
    std::cout << "----" << std::endl;
    std::cout <<getOnes(4) << std::endl;
    std::cout << "----" << std::endl;
    std::cout <<getOnes(5) << std::endl;
    std::cout << "----" << std::endl;
    std::cout <<getOnes(6) << std::endl;
    std::cout << "----" << std::endl;
    std::cout <<getOnes(7) << std::endl;
    std::cout << "----" << std::endl;*/
    std::cout << rangeOnes(0,1589) << std::endl;
    std::cout << rangeOnes(5,8) << std::endl;
    std::cout << rangeOnes(9,15) << std::endl;
    std::cout << rangeOnes(16,24000) << std::endl;
    return 0;
}


