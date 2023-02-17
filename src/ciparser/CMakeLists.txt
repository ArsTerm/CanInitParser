include(CompileOptions)

set(target_name ciparser)

add_executable(${target_name} main.cpp)

target_link_libraries(${target_name} PRIVATE CanInitParser)
target_include_directories(${target_name} PRIVATE ${CMAKE_SOURCE_DIR}/src/CanInitParser)
