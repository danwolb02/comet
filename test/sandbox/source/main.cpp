#include <comet/base.hpp>
#include <comet/graphics/window.hpp>
#include <comet/graphics/vertex_buffer.hpp>
#include <comet/graphics/index_buffer.hpp>
#include <comet/graphics/vertex_array.hpp>
#include <comet/graphics/renderer.hpp>

using namespace comet;

int main()
{
    Window window(1280, 720, "Comet Application");
    VertexBuffer vertex_buffer({-0.5f, -0.5f, 0.5f, -0.5f, 0.0f,  0.5f });
    IndexBuffer index_buffer({0, 1, 2});
    VertexArray vertex_array(move(index_buffer));
    vertex_array.upload(move(vertex_buffer), 0, 2, 0);

    Renderer renderer;

    String vertex_source = R"(
    #version 410 core

    layout (location = 0) in vec2 position_vertex;

    void main()
    {
        gl_Position = vec4(position_vertex, 0.0, 1.0);
    }
    )";

    String fragment_source = R"(
    #version 410 core

    out vec4 out_color;

    void main()
    {
        out_color = vec4(1, 0, 0, 1);
    }
    )";

    Shader shader(vertex_source, fragment_source);

    while (!window.should_close())
    {
        window.update();
        renderer.render(vertex_array, shader);
    }

    return 0;
}
