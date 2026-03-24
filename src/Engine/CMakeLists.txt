project(Engine)

add_subdirectory(Code)
add_subdirectory(Include)
add_subdirectory(OpenGL)

target_sources(Engine PRIVATE Engine.cpp)
target_include_directories(Engine PRIVATE ./)
