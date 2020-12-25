sandbox_source_files = files(
    'source/main.cpp'
)

sandbox_executable = executable(
    'sandbox',
    sandbox_source_files,
    dependencies : comet_dependency
)

test('sandbox', sandbox_executable)
