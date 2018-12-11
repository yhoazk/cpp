#include <iostream>
#include <boost/asio.hpp>

/**
 * Server for the ping pong conversation
 *  
 */

int main(int argc, char const *argv[])
{
  boost::asio::io_service ios;

  ios.run();
  return 0;
}
