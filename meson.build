project('comet', 'cpp', version : '0.1.0')

comet_source_files = files(
    'source/comet/hello.cpp'
)

comet_header_files = files(
    'include/comet/hello.hpp'
)

comet_dependencies = []

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
