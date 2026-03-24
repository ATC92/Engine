project(Engine)

file(GLOB_RECURSE gl_cpp RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

target_sources(Engine PRIVATE ${gl_cpp})

add_subdirectory(Shaders)

target_include_directories(Engine PRIVATE ./)
