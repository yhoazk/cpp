#include <boost/python.hpp>


char const* hello(){
    return "Hello";
}

BOOST_PYTHON_MODULE(hello_text) {
    using namespace boost::python;
    def("geet", hello);
}