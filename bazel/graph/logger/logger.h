
#ifndef __LOGGER__
#define __LOGGER__

#include <string>
#include <iostream>

class logger {
public:
logger(std::string name):name(name){};

void info(std::string log) noexcept;
void warn(std::string log) noexcept;
void error(std::string log) noexcept;
void fatal(std::string log) noexcept;

private:
    std::string name;
};

#endif /* __LOGGER__ */