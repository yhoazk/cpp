#include <iostream>


struct persistent_wrapper{
    float kk;

    public:
    persistent_wrapper( float n ): kk{n}{

    };



};


struct crc_usr{


    crc_usr(): pa{persistent_wrapper(1)}, pb{persistent_wrapper(2)}, pc{persistent_wrapper(3)}, pd{persistent_wrapper(4)}{
        pa = persistent_wrapper(9);
        pb = persistent_wrapper(8);
        pc = persistent_wrapper(7);
        pd = persistent_wrapper(6);
    }

    persistent_wrapper pa;
    persistent_wrapper pb;
    persistent_wrapper pc;
    persistent_wrapper pd;
};

int main(int argc, char const *argv[])
{
    crc_usr fefe;
    return sizeof(fefe);
}
