add_executable(Engine main.cpp)

target_compile_definitions(Engine PRIVATE $<$<CONFIG:Debug>:DEBUG>)

set_target_properties(Engine PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/$<CONFIG>"
)

target_link_libraries(Engine PRIVATE glfw glad_gl_core_33)
