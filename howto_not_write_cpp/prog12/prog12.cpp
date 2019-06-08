// Hurry up and wait
// it was designed to send data over a serial line. Although the serial line
// was capable of doing 960 characters per second, we were lucky to get 300
// characters a second

/************************************************
* send_file -- Send a file to a remote link *
* (Stripped down for this example.) *
************************************************/
#include <iostream>
#include <fstream>
#include <stdlib.h>
// Size of a block
const int BLOCK_SIZE = 256;
/************************************************
* send_block -- Send a block to the output port*
************************************************/
void send_block( std::istream &in_file, // The file to read
        std::ostream &serial_out // The file to write
) {
  int i; // Character counter
  for (i = 0; i < BLOCK_SIZE; ++i) {
    int ch; // Character to copy
    ch = in_file.get();
    std::cout << "ch:" << ch << '\n';
    serial_out.put(ch);
    serial_out.flush(); // should not flush on every char
  }
}


void send_block_v2(std::istream &in_file, std::ostream &serial_out){
  int i;
  int ch;
  for(i =0; i < BLOCK_SIZE && ((in_file.rdstate() & std::ifstream::eofbit) != 0); ++i){
    ch = in_file.get();
    serial_out.put(ch);
  }
  serial_out.flush();
}

void test_failbit(){
  std::ifstream is;
  is.open("prog12");
  if ( (is.rdstate() & std::ifstream::failbit ) != 0 ){
    std::cerr << "Error opening 'test.txt'\n";
  } else {
    std::cerr << "Open worked\n";
  }
}

int main(){
  // The input file
  std::cout << "Filename " << __FILE__ << '\n';
  std::ifstream in_file(__FILE__);
  // The output device (faked)
  std::ofstream out_file("/dev/null");
  if (in_file.bad()){
    std::cerr << "Error: Unable to open input file\n";
    exit (8);
  }
  if (out_file.bad()){
    std::cerr << "Error: Unable to open output file\n";
    exit (8);
  }
  test_failbit();

  while (!in_file.eof()){
  // The original program output
  // a block header here
  send_block_v2(in_file, out_file);
  std::cout << "Block send\n";
  // The original program output a block
  // trailer here. It also checked for
  // a response and resent the block
  // on error
  }
  return (0);
}