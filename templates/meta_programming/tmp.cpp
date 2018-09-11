#include <iostream>

/*  Templates that calculate a value */
/* In this case the templated class BITS_SET calculates how many bits are set
   in the unsigned char */
template<unsigned char byte>
class BITS_SET {
    public:
    enum {
        B0 = (byte & (0x01 << 0))? 1:0,
        B1 = (byte & (0x01 << 1))? 1:0,
        B2 = (byte & (0x01 << 2))? 1:0,
        B3 = (byte & (0x01 << 3))? 1:0,
        B4 = (byte & (0x01 << 4))? 1:0,
        B5 = (byte & (0x01 << 5))? 1:0,
        B6 = (byte & (0x01 << 6))? 1:0,
        B7 = (byte & (0x01 << 7))? 1:0,
    };
    enum{RESULT = (B0 + B1 + B2 + B3 + B4 + B5 + B6 + B7)};
};
#if 0
/* Why the templating stops at 0?? */
template <int i>
class FACTOR{
    public:
    enum{ RESULT = i * FACTOR<i-1>::RESULT};
};

template<>
class FACTOR<1>{
    public:
        enum{ RESULT = 1};
}
#endif
/*  Templates that generate code */
template<unsigned long init, unsigned long step, unsigned long end>
class loop {
public:
    static void EXEC() {looponce<init-end>::EXEC();}

    template<unsigned long N>
    class looponce{
        public:
            static void EXEC(){std::cout << N+end << std::endl; looponce<N-step>::EXEC();}
    };

    class looponce<0>{
        public:
            static void EXEC(){std::cout <<end<<std::endl;}
    };
};

int main(int argc, char const *argv[])
{
    //This for goes for the number of bits that are on (1)
    for(unsigned char i=0; i < BITS_SET<0xFF>::RESULT; ++i){
        std::cout << "\ni: " << i + 0; // This looks dumb, but with out the 0 the chars are printed as hex 
    }
//    std::cout << "Factorial of 5 is: " << FACTOR<5>::RESULT;
    loop<10,1,0>::EXEC();
    std::cout << std::endl;
    return 0;
}
