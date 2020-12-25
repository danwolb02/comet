#include <iostream>
#include <comet/hello.hpp>

namespace comet
{
    auto hello() -> void
    {
        std::cout << "Hello!\n";
    }
}
