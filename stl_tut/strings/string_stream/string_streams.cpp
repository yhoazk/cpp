#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <map>

std::map<uint8_t, const char*> notes{
    {1, "AAA"},
    {2, "BBB"},
    {3, "CCC"},
};
int main(int argc, char const *argv[])
{
    std::stringstream ss;
    ss << "Getting the stuff from the array\n";
    for (auto &&i : notes)
    {
        ss << i.second;
    }
    ss << notes[2];
    std::cout << ss.str();

    return 0;
}
