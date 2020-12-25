#include <comet/graphics/window.hpp>
#include <comet/graphics/vertex_buffer.hpp>

using namespace comet;

int main()
{
    Window window(1280, 720, "Comet Application");
    VertexBuffer vertex_buffer({34, 44, 66});

    while (!window.should_close())
    {
        window.update();
    }

    return 0;
}
