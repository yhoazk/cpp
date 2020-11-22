#include <iostream>
#include <set>
#include <array>
#include <fstream>
#include <set>

using ip_t = std::array<uint8_t, 4>;
using mac_t = std::array<uint8_t, 6>;
using arpentry_t = std::pair<ip_t, mac_t>;
using arpentries_t = std::set<arpentry_t>;


void report_to_file(/*const arpentries_t& table,*/ const std::string& fname) {
    std::ofstream report("/tmp/"+fname, std::ios::binary);
    report << "sdfsdfsdf\n";
    report.close();
}

int main(){

    report_to_file("report");
    return 0;
}