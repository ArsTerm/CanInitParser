include(CompileOptions)

set(target_name ciparser)

add_executable(${target_name} main.cpp)

target_link_libraries(${target_name} PRIVATE CanInitParser CanInitCompiler)
target_include_directories(${target_name} PRIVATE ${ROOT_DIRECTORY}/src/CanInitParser ${ROOT_DIRECTORY}/src/CanInitCompiler)
