#include <comet/base.hpp>
#include <comet/graphics/renderer.hpp>
#include <comet/graphics/window.hpp>

using namespace comet;

int main()
{
	Window window(1280, 720, "Comet Application");
	VertexBuffer vertex_buffer({-1, 1, 0, 1, 1, 0, 1, -1, 0, -1, -1, 0});
	IndexBuffer index_buffer({0, 1, 2, 0, 3, 2});
	VertexArray vertex_array(move(index_buffer));
	vertex_array.upload(move(vertex_buffer), 0, 3, 0);

	Renderer renderer(window);

	String vertex_source = R"(
    #version 410 core

    layout (location = 0) in vec3 position_vertex;

    uniform mat4 projection_matrix;
	uniform mat4 view_matrix;
    uniform mat4 transformation_matrix;

    void main()
    {
        gl_Position = projection_matrix * view_matrix * transformation_matrix * vec4(position_vertex, 1.0);
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

	Matrix4f transformation_matrix(1);

	Matrix4f view_matrix(1);
	view_matrix = view_matrix.translate(0, 0, -10);

	while (!window.should_close()) {
		window.update();

		if (window.get_width() == 0 || window.get_height() == 0) continue;

		Matrix4f projection_matrix = perspective(
		(f32) window.get_width() / (f32) window.get_height(), 1.0472, 0.1, 100);
		transformation_matrix = transformation_matrix.rotate(0, 0.1, 0);

		renderer.render(vertex_array, shader, transformation_matrix,
						view_matrix, projection_matrix);
	}

	return 0;
}
