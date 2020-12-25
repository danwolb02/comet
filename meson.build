project('comet', 'cpp', version : '0.1.0')

comet_source_files = files(
    'source/comet/graphics/window.cpp',
    'source/comet/graphics/vertex_buffer.cpp',
    'source/comet/graphics/index_buffer.cpp',
    'source/comet/graphics/vertex_array.cpp',
    'source/comet/graphics/renderer.cpp',
)

comet_header_files = files(
    'include/comet/external.hpp',
    'include/comet/graphics/window.hpp',
    'include/comet/pch.hpp',
    'include/comet/types.hpp',
    'include/comet/graphics/vertex_buffer.hpp',
    'include/comet/graphics/index_buffer.hpp',
    'include/comet/graphics/vertex_array.hpp',
    'include/comet/graphics/renderer.hpp',
)

comet_dependencies = [
    dependency('glfw3'),
    dependency('gl'),
    dependency('glew'),
]

comet_library = library(
    'comet',
    [comet_source_files, comet_header_files],
    cpp_pch : 'include/comet/pch.hpp',
    dependencies : comet_dependencies,
    include_directories : 'include',
    install : true
)

comet_dependency = declare_dependency(
    include_directories : 'include',
    link_with : comet_library
)

subdir('test/sandbox')
