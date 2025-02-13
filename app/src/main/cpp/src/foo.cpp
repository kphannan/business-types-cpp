
#include <iostream>
#include <iomanip>

#include "bar.hpp"
#include "baz.hpp"

int main(int argc, const char **argv)
{
    std::cout << "Hello world\n";

    lib1::barFN();
    lib2::bazFN();
}