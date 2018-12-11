#include <iostream>
#include <boost/asio.hpp>

int main(int argc, char const *argv[])
{
  boost::asio::io_service ios;

  ios.run();
  return 0;
}
