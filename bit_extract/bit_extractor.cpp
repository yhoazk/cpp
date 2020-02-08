/* Given an array, an offset and a with extract the bits
   indicated by the offset and width with the type indicated. */

#include <iostream>
#include <iomanip>
#include <array>
#include <sstream>
#include <bitset>

// template<typename Array, typename RT>
// RT extract_bits(Array& array, size_t offset, size_t width, RT& val){
//     uint8_t ul = offset + width; // upper limit ie where lies the last interesing bit
//     auto start_byte = offset / 8;
//     auto rem = ul % 8;        // this tell us if we should look to the next byte
//     auto interesing_bytes = (ul / 8);
//     auto end_byte = (ul / 8);
//     std::cout << "inter: " << interesing_bytes << '\n';
//     interesing_bytes += (rem>0? 1u:0u);

//     std::cout << "inter: " << interesing_bytes << '\n';
//     std::cout << "ul: " << static_cast<int>(ul) << '\n';
//     uint8_t bits_in_first_byte = offset - (8 * start_byte);
//     uint8_t left_mask = 0xffu << bits_in_first_byte;
//     val = (array[start_byte] & left_mask);
//     val <<= ((8 * (sizeof(RT) -1)) - (8-bits_in_first_byte) );

//     std::cout << "xx: " << std::hex << static_cast<int>(left_mask) << '\n';
//     std::cout.copyfmt(std::ios(NULL));
//     for (size_t i = 0; i < interesing_bytes; i++) {
//         std::cout << "maxk" << '\n';
//     }

//     return val;
// }

// template<typename Array, typename RT>
// RT extract_bits(Array& array, size_t offset, size_t width, RT& val){
//     val = 0;
//     uint8_t start_byte = offset / 8;
//     uint8_t end_byte = (offset + width) / 8;
//     uint8_t fb_msb = 8 - ( offset %8); // first byte most significant bits
//     uint8_t trailing_bit = (offset + width) % 8;

//     if(offset % 8 != 0){
//         uint8_t msb_mask = ~(0xffu >> fb_msb);
//         val = array[start_byte] & msb_mask;
//         val >>= 8-fb_msb; // width is 1 based
//         start_byte++;

//     } else { fb_msb = 0;}

//     for (size_t i = start_byte; i < end_byte; i++) {
//         width -= 8;
//         if(fb_msb == 0){
//             val |= array[i] << ((i-1)*8);  // -1 por que val es base 0
//         } else {
//             val |= array[i] << (width-1);
//         }
//                 // if(fb_msb != 0)
//         //     val >>= ( width );

//     }

//     if(trailing_bit > 0){
//         uint8_t trail_mask = ~(0xffu << trailing_bit);
//         RT k = (array[end_byte] & trail_mask);
//         if(fb_msb != 0)
//             k <<= width-fb_msb - 1;//(fb_msb + (end_byte*8));
//         if(start_byte != end_byte)
//             k <<= (end_byte * 8) - trailing_bit-1;
//         val |= k;
//     }
//     return val;
// }

template<typename Array, typename RT>
RT extract_bits(Array& array, size_t offset, size_t width, RT& val){
    val = 0;
    uint8_t start_byte = offset / 8;
    uint8_t end_byte = (offset + width) / 8;
    uint8_t fb_msb = (8 - ( offset %8)) % 8; // first byte most significant bits
    uint8_t trailing_bit = (offset + width) % 8;

    if(fb_msb != 0){
        uint8_t msb_mask = ~(0xffu >> fb_msb);
        val = array[start_byte] & msb_mask;
        val >>= 8-fb_msb; // width is 1 based
        start_byte++;
    }

    for (size_t i = start_byte; i < end_byte; i++) {
        // width -= 8;
        // if(fb_msb == 0){
        uint8_t shift = abs(((i-1)*8) - fb_msb);
        uint8_t arrv = array[i];
        val |= arrv << shift;  // -1 por que val es base 0
        // } else {
            // val |= array[i] << (width-1);
        // }
                // if(fb_msb != 0)
        //     val >>= ( width );

    }

    if(trailing_bit > 0){
        uint8_t trail_mask = ~(0xffu << trailing_bit);
        RT k = (array[end_byte] & trail_mask);
        // if(fb_msb != 0)
            // k <<= width-fb_msb - 1;//(fb_msb + (end_byte*8));
        // if(start_byte != end_byte)
            k <<= (width - trailing_bit);
        val |= k;
    }
    return val;
}
int main(int argc, char const *argv[])
{
    std::array<uint8_t, 5> my_bytes {
        0b1101'0000,
        0b1111'0111,
        0b0000'0111,
        0b0000'1111,
        0b0001'1011,
    };
    uint16_t ret16;
    uint8_t ret8;

    std::bitset<16> test;

    if( argc < 3) {
        extract_bits(my_bytes, 2,15, ret16);
        extract_bits(my_bytes, 8,12, ret16);
        extract_bits(my_bytes, 6,5, ret8);
        extract_bits(my_bytes, 8,5, ret8);
    } else {
        std::cout << "arg count " << argc << '\n';
        std::cout << "arg 1 " << argv[1] << '\n';
        std::cout << "arg 2 " << argv[2] << '\n';
        std::stringstream ss{argv[1]};
        int offset;
        int width;
        ss >> offset;
        ss.clear();
        ss.str(argv[2]);
        ss >> width;
        std::cout << "offset " << offset << " wdt " << width << '\n';
        extract_bits(my_bytes, offset, width, ret8);
    }
    std::cout << static_cast<unsigned int >(ret8) << '\n';
    return 0;
}
