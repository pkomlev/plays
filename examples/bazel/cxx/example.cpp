#include <boost/core/noncopyable.hpp>
#include <iostream>

#include "fmt/format.h"

class Example : boost::noncopyable {};

int main(int argc, char *argv[]) {
  std::cout << fmt::format("Hello {}!", "fmt") << std::endl;
  return 0;
}