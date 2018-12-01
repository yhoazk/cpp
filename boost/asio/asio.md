# ASIO

Asynchornous IO makes possible to make calls and return inmediatelly witout
result from the call. The result will be processed in the future.
In the mean time our process can continue with its work.

The difference with boost.threads and asio is that threads is for accessing 
internal resources. Asio is for external resources that most likely go through
a network card.

## Services and objects

In the asio library, two abstractions are used: Services and objects.
The services abstract the details of the operating system, while the objects
implement calls a developer would need.

Users of the asio library normally do not interact with the services but with
the objects `boost::asio::io_service`. Every program based on asio uses an
`io_service` object.

There's only one `io_service` object, but several IO objects as they are task
oriented. If we want to send TCP use `boost::asio::ip::tcp::socket` if serial
is to be used `boost::asio::serial_port` if a timer is needed use
`boost::asio::steady_timer` this call uses the OS to notify the process.