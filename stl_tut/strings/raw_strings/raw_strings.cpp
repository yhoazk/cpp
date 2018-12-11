#include <iostream>
#include <string>

using namespace std;

const char* raw_string = R"(fsdfs
    sdfsdfsd
    sdfsdf)";
int main()
{
  cout << "Raw string: Note the indentation";
  cout <<  raw_string;
  return 0;
}
