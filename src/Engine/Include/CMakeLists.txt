project(Engine)

add_subdirectory(Components)
add_subdirectory(Core)
add_subdirectory(Inputs)
add_subdirectory(Render)
add_subdirectory(System)
add_subdirectory(Utils)

target_include_directories(Engine PRIVATE ./)
