#include <iostream>
#include <fstream>
#include <array>

#include "fir.h"
/*
get data from the mic
arecord -d 5 -f FLOAT_LE  -t raw test.raw
default 8000 Hz

arecord -s 10240 -f FLOAT_LE -r 2000 -t raw test.raw
aplay -s 10240 -f FLOAT_LE -r 2000 -t raw test.raw
http://t-filter.engineerjs.com/
*/

struct sound {
    float left;
    float rigth;
};


int main(int argc, char const *argv[])
{
    sound *sample;
    std::array<char, 2048> buffer;
    auto file = std::ifstream("test.raw");
    //std::cout << "file:" << file.bad() << "\n";
    while(file.read(buffer.data(), 2048)){
        //std::cout << "Read:: " << file.gcount() << '\n';
        for (size_t i = 0; i < file.gcount() / sizeof(sound); i++){
            sample = reinterpret_cast<sound*>(buffer.data() + i * sizeof(sound));
            std::cout << sample->left << " , ";
            std::cout << sample->rigth << '\n';
            /* code */
        }
        
    }
        //std::cout << "Read:: " << file.gcount() << '\n';

    return 10;
}
