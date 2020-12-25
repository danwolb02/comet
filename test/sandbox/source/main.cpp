#include <comet/graphics/window.hpp>

using namespace comet;

int main()
{
    Window window(1280, 720, "Comet Application");

    while (!window.should_close())
    {
        window.update();
    }

    return 0;
}
