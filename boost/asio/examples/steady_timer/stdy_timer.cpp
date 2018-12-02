#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>
#include <chrono>
#include <iostream>


using namespace boost::asio;

int main(int argc, char const *argv[])
{
  io_service ioservice;
  /* After the time passed in the constructor of the steady_timer expires
     the lambda is called  */
  steady_timer timer{ioservice, std::chrono::seconds{5}};
  timer.async_wait([](auto n){ 
    /* In this case the auto is const boost::system::error:code & */
    std::cout << "End 5 secs\n";
  });

  steady_timer timer2{ioservice, std::chrono::seconds{2}};
  timer2.async_wait([](auto n){
    std::cout << "End 2 secssss\n";
  });
  /* This call gives the control to the OS to call the async procedures
     This is a blocking call */
  ioservice.run();
  return 0;
}
