include(CompileOptions)

set(target_name CanInitCompiler)

find_package(Qt5 REQUIRED COMPONENTS Core REQUIRED)

add_library(${target_name} SHARED)
target_sources(${target_name} PRIVATE caninitcompiler_global.h compiler.cpp compiler.h)

target_compile_definitions(${target_name} PRIVATE CANINITCOMPILER_LIBRARY)

target_link_libraries(${target_name} PRIVATE CanInitParser)
target_include_directories(${target_name} PRIVATE ${ROOT_DIRECTORY}/src/CanInitParser)

target_link_libraries(${target_name} PRIVATE Qt5::Core)

set_compile_options(${target_name})
