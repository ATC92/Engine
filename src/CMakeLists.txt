project(Engine)

add_subdirectory(Main)
add_subdirectory(Game)
add_subdirectory(Engine)

target_include_directories(Engine PRIVATE ./)
