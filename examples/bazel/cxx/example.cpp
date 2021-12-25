#include <iostream>

#include <boost/core/noncopyable.hpp>

class Example : boost::noncopyable
{
};

int main(int argc, char *argv[])
{
    std::cout << "Hello Boost!" << std::endl;
    return 0;
}