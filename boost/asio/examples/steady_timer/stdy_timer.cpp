#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>
#include <chrono>
#include <iostream>


using namespace boost::asio;

int main(int argc, char const *argv[])
{
  io_service ioservice;

  steady_timer timer{ioservice, std::chrono::seconds{5}};
  timer.async_wait([](auto n){
    std::cout << "End 5 secs\n";
  });

  steady_timer timer2{ioservice, std::chrono::seconds{2}};
  timer2.async_wait([](auto n){
    std::cout << "End 2 secssss\n";
  });

  ioservice.run();
  return 0;
}
