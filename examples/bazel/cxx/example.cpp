#include <boost/core/noncopyable.hpp>
#include <iostream>

class Example : boost::noncopyable {};

int main(int argc, char *argv[]) {
  std::cout << "Hello Boost!" << std::endl;
  return 0;
}